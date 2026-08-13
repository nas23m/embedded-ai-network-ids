import pandas as pd
import numpy as np
from sklearn.preprocessing import LabelEncoder
import joblib

cols = [
    "duration", "protocol_type", "service", "flag", "src_bytes", "dst_bytes",
    "land", "wrong_fragment", "urgent", "hot", "num_failed_logins",
    "logged_in", "num_compromised", "root_shell", "su_attempted", "num_root",
    "num_file_creations", "num_shells", "num_access_files", "num_outbound_cmds",
    "is_host_login", "is_guest_login", "count", "srv_count", "serror_rate",
    "srv_serror_rate", "rerror_rate", "srv_rerror_rate", "same_srv_rate",
    "diff_srv_rate", "srv_diff_host_rate", "dst_host_count", "dst_host_srv_count",
    "dst_host_same_srv_rate", "dst_host_diff_srv_rate", "dst_host_same_src_port_rate",
    "dst_host_srv_diff_host_rate", "dst_host_serror_rate", "dst_host_srv_serror_rate",
    "dst_host_rerror_rate", "dst_host_srv_rerror_rate", "label", "difficulty"
]

EASY_FEATURES = [
    "duration", "protocol_type", "service", "flag",
    "src_bytes", "dst_bytes", "land", "wrong_fragment", "urgent",
]

MEDIUM_FEATURES = [
    "count", "srv_count",
    "serror_rate", "srv_serror_rate", "rerror_rate", "srv_rerror_rate",
    "same_srv_rate", "diff_srv_rate", "srv_diff_host_rate",
    "dst_host_count", "dst_host_srv_count",
    "dst_host_same_srv_rate", "dst_host_diff_srv_rate",
    "dst_host_same_src_port_rate", "dst_host_srv_diff_host_rate",
    "dst_host_serror_rate", "dst_host_srv_serror_rate",
    "dst_host_rerror_rate", "dst_host_srv_rerror_rate",
]

feature_cols = EASY_FEATURES + MEDIUM_FEATURES

train = pd.read_csv("data/train.csv", names=cols)
test = pd.read_csv("data/test.csv", names=cols)

train["binary_label"] = (train["label"] != "normal").astype(int)
test["binary_label"] = (test["label"] != "normal").astype(int)

cat_cols = [c for c in ["protocol_type", "service", "flag"] if c in feature_cols]
for c in cat_cols:
    le = LabelEncoder()
    train[c] = le.fit_transform(train[c])
    test[c] = test[c].map(lambda x: x if x in le.classes_ else "UNK")
    le.classes_ = np.array(list(le.classes_) + ["UNK"])
    test[c] = le.transform(test[c])

# Load the trained model to get its own predictions for comparison
clf = joblib.load("models/rf_model_reduced.joblib")

# Grab 10 sample rows: mix of normal and attack, for a balanced spot-check
sample = pd.concat([
    test[test["binary_label"] == 0].sample(5, random_state=1),
    test[test["binary_label"] == 1].sample(5, random_state=1),
])

X_sample = sample[feature_cols]
y_true = sample["binary_label"].values
y_pred_python = clf.predict(X_sample)
y_proba_python = clf.predict_proba(X_sample)

import io
import sys

output_lines = []

def emit(line=""):
    output_lines.append(line)

emit("// Auto-generated test vectors for C verification")
emit("// Format: {features...}, true_label, python_predicted_label, python_attack_probability")
emit()
emit(f"#define NUM_TEST_SAMPLES {len(sample)}")
emit(f"#define NUM_FEATURES {len(feature_cols)}")
emit()
emit("double test_inputs[NUM_TEST_SAMPLES][NUM_FEATURES] = {")
for i in range(len(sample)):
    row = X_sample.iloc[i].values
    row_str = ", ".join(f"{v:.6f}" for v in row)
    emit(f"    {{{row_str}}},  // true={y_true[i]} python_pred={y_pred_python[i]} python_prob_attack={y_proba_python[i][1]:.6f}")
emit("};")
emit()
emit("int expected_labels[NUM_TEST_SAMPLES] = {" + ", ".join(str(v) for v in y_true) + "};")
emit("int python_predictions[NUM_TEST_SAMPLES] = {" + ", ".join(str(v) for v in y_pred_python) + "};")

with io.open("models/test_vectors.h", "w", encoding="utf-8", newline="\n") as f:
    f.write("\n".join(output_lines) + "\n")

print("Wrote models/test_vectors.h successfully.")
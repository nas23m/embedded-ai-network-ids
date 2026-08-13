import pandas as pd
import numpy as np
from sklearn.preprocessing import LabelEncoder
from sklearn.ensemble import RandomForestClassifier
from sklearn.metrics import classification_report, accuracy_score
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

train = pd.read_csv("data/train.csv", names=cols)
test = pd.read_csv("data/test.csv", names=cols)

# Binary label: 0 = normal, 1 = attack
train["binary_label"] = (train["label"] != "normal").astype(int)
test["binary_label"] = (test["label"] != "normal").astype(int)

cat_cols = ["protocol_type", "service", "flag"]
encoders = {}
for c in cat_cols:
    le = LabelEncoder()
    train[c] = le.fit_transform(train[c])
    test[c] = test[c].map(lambda x: x if x in le.classes_ else "UNK")
    le.classes_ = np.array(list(le.classes_) + ["UNK"])
    test[c] = le.transform(test[c])
    encoders[c] = le

feature_cols = [c for c in cols if c not in ("label", "difficulty")]

X_train, y_train = train[feature_cols], train["binary_label"]
X_test, y_test = test[feature_cols], test["binary_label"]

# Training Using Random Forest Classifier (Low value for max_depth to make it deploible on low resource devices)
clf = RandomForestClassifier(n_estimators=10, max_depth=5, class_weight="balanced", random_state=42)
clf.fit(X_train, y_train)
#----------------------------------------------------------------------------------------------
preds = clf.predict(X_test)
print("Accuracy:", accuracy_score(y_test, preds))
print(classification_report(y_test, preds, target_names=["normal", "attack"]))

joblib.dump(clf, "models/rf_model.joblib", compress=3)
print("Model saved to models/rf_model.joblib")
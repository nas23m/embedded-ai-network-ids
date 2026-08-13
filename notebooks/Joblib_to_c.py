import m2cgen as m2c
import joblib

model = joblib.load("C:/Users/nassim/Desktop/edge_security/models/rf_model_reduced.joblib")

code = m2c.export_to_c(model)

with open("rf_model_reduced.c", "w") as f:
    f.write(code)

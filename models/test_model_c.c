#include <stdio.h>

// Declare the score() function from rf_model_reduced.c
void score(double *input, double *output);

// PASTE the generated test_inputs[][], expected_labels[], and
// python_predictions[] arrays here (output of generate_test_vectors.py)
#include "test_vectors.h"

int main() {
    int mismatches = 0;

    for (int i = 0; i < NUM_TEST_SAMPLES; i++) {
        double output[2];
        score(test_inputs[i], output);

        // output[0] = probability normal, output[1] = probability attack
        int c_prediction = (output[1] > output[0]) ? 1 : 0;

        printf("Sample %d: true=%d  python_pred=%d  c_pred=%d  "
               "c_prob_normal=%.4f  c_prob_attack=%.4f\n",
               i, expected_labels[i], python_predictions[i], c_prediction,
               output[0], output[1]);

        if (c_prediction != python_predictions[i]) {
            printf("  >>> MISMATCH: C prediction differs from Python!\n");
            mismatches++;
        }
    }

    printf("\n--- Summary ---\n");
    printf("Total samples tested: %d\n", NUM_TEST_SAMPLES);
    printf("Mismatches (C vs Python): %d\n", mismatches);

    if (mismatches == 0) {
        printf("PASS: C model matches Python model on all test samples.\n");
    } else {
        printf("FAIL: conversion bug detected, do not trust the C model yet.\n");
    }

    return mismatches == 0 ? 0 : 1;
}

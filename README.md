# Embedded AI Network Intrusion Detection System

An ESP32-based Network Intrusion Detection System (NIDS) that runs a 
machine learning model entirely on-device — no cloud, no external compute.
Trained on the NSL-KDD dataset, converted to native C, and deployed with 
a hand-built real-time feature extraction engine in C++.

## Why this project

[2-3 sentences on motivation — combining embedded systems, AI, and network 
security into one working pipeline]

## Architecture

[Diagram or ASCII flow: Raw WiFi packet → C++ rolling-feature buffer → 
28-feature vector → Random Forest (C) → prediction]

## Results

- Model accuracy: 76.7% (NSL-KDD test set, includes unseen attack types)
- Model size: 70KB (compressed)
- Flash usage: 893KB / 1.31MB (68%)
- RAM usage: 54KB / 327KB (16%)

## Tech Stack

- Python (scikit-learn, pandas) — model training
- m2cgen — model-to-C conversion
- C++ — embedded feature engineering (circular buffer, rolling window statistics)
- ESP32 / Arduino — WiFi promiscuous packet capture, deployment

## Project Structure

[brief explanation of the folders above]

## Setup / Reproduction

[Step-by-step: how someone else could clone this and reproduce your results]

## Known Limitations

[Be honest — e.g., TCP flag approximation from single packets, placeholder 
values for duration/land features, single-channel WiFi listening]

## Future Work

[Attack simulation results, multi-channel support, etc.]

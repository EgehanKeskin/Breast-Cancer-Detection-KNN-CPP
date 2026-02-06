#  Breast Cancer Detection - KNN Implementation in C++

This project is a **Machine Learning** application that classifies breast cancer tumors based on clinical features. It is implemented from scratch using standard **C++**, without relying on external ML libraries like scikit-learn.

## 📊 Project Overview
The algorithm processes the `Wisconsin Breast Cancer Dataset` containing 569 patients. It analyzes 30 different clinical features (radius, texture, perimeter, etc.) to predict whether a tumor is **Malignant (1)** or **Benign (0)**.

* **Algorithm:** K-Nearest Neighbors (KNN)
* **Distance Metric:** Euclidean Distance
* **Accuracy:** 94.72%

##  Technical Implementation
The project demonstrates core software engineering and data science principles:

* **Data Structures:** Used `struct` for data encapsulation and `std::vector` for dynamic memory management.
* **Data Parsing:** Extracted features from CSV files using `std::ifstream` and `std::stringstream`.
* **Logic:** The KNN function calculates the distance between a query patient and the entire dataset, sorts the distances, and performs a majority vote among the top `K=5` neighbors.



##  Performance Results
The model was tested against the entire dataset to evaluate its predictive power:

| Parameter | Value |
| :--- | :--- |
| **Total Patients Tested** | 569 |
| **Correct Predictions** | 539 |
| **Incorrect Predictions** | 30 |
| **Overall Accuracy** | **94.72%** |



##  How to Run
1. Ensure `main.cpp` and `data.csv` are in the same directory.
2. Compile using a C++ compiler (Visual Studio, GCC, Clang).
3. Run the executable; the analysis and accuracy report will be displayed in the console.

---
*Disclaimer: This project is for educational purposes only and is not intended for medical diagnosis.*

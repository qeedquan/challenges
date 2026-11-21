#!/usr/bin/env python3

"""

Compute the sample covariance matrix without using np.cov. First center each feature:
Xc = X - mu

Then compute:
E = (Xc^T * Xc) / (N - 1)

Here, X has N samples and D features, mu is the vector of feature means,
Xc is the centered data, and E is the DxD sample covariance matrix.
Return E as a NumPy array.

Examples
Input: X = [[1, 2], [2, 3], [3, 4]]

Output: [[1.0, 1.0], [1.0, 1.0]]

Explanation: Both features vary together by the same amount after centering.

Input: X = [[1, 0], [0, 1]]

Output: [[0.5, -0.5], [-0.5, 0.5]]

Hint 1
Use X - np.mean(X, axis=0) to center every feature.

Hint 2
Use centered.T @ centered before dividing by X.shape[0] - 1.

Requirements
Center each feature independently
Divide by N minus 1 for sample covariance
Do not use np.cov
Return a NumPy array of shapes (D, D)

Constraints
X is a rectangular numeric list with shape (N, D)
2 <= N <= 10,000
Use NumPy only

"""

import numpy as np

def covariance_matrix(X: list) -> np.ndarray:
    X = np.array(X)
    Xc = X - np.mean(X, axis=0)
    return (np.transpose(Xc) @ Xc) / (X.shape[0] - 1)

def main():
    print(covariance_matrix([[1, 2], [2, 3], [3, 4]]))
    print(covariance_matrix([[1, 0], [0, 1]]))

main()

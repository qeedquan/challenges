#!/usr/bin/env python3

"""

Compute the coefficient of determination for one-dimensional regression targets and predictions:

R^2 = 1 - Sum[i] (y[i]-y_h[i])^2
          ------------------------
          Sum[i] (y[i] - y_m)^2

Examples
Input: y_true = [3, 4, 5], y_pred = [2.9, 4.1, 5.0]

Output: 0.99

Explanation: The residual sum of squares is 0.02 and the total sum of squares is 2, so the score is 1 - 0.02 / 2.

Input: y_true = [1, 1, 1], y_pred = [1, 1, 1]

Output: 1.0

Input: y_true = [1, 1, 1], y_pred = [0, 2, 1]

Output: 0.0

Hint 1
Use np.sum((y_true - y_pred) ** 2) for the residual sum of squares.

Hint 2
Check whether the total sum of squares is zero before applying the fraction.

Requirements
Compute the residual and total sums of squares with NumPy
Apply the stated convention when all targets are equal
Return a Python float
Constraints
y_true and y_pred are equal-length, nonempty one-dimensional numeric lists
Each list contains at most 10^6 values
Use NumPy only

"""

import numpy as np

def r2_score(y_true: list, y_pred: list) -> float:
    y_true = np.array(y_true)
    y_pred = np.array(y_pred)
    y_mean = np.mean(y_true)
    y_num = np.sum((y_true - y_pred)**2)
    y_den = np.sum((y_true - y_mean)**2)
    if y_den == 0:
        if np.allclose(y_num, y_den):
            return 1
        return 0
    return 1 - y_num/y_den

def main():
    print(r2_score([3, 4, 5], [2.9, 4.1, 5.0]))
    print(r2_score([1, 1, 1], [1, 1, 1]))
    print(r2_score([1, 1, 1], [0, 2, 1]))

main()

#!/usr/bin/env python3

"""

Compute the mean Huber loss between targets and predictions.
For error e = y_true - y_pred

Lδ(e) = 0.5 * e^2         if |e| <= δ
        δ*(|e| - 0.5*δ)   if |e| > δ

Here δ is delta. Apply the piecewise loss elementwise and return its mean as a Python float.

Examples
Input: y_true = [1, 2, 3], y_pred = [1.5, 1.7, 2.5], delta = 1.0

Output: 0.098333

Explanation: Every absolute error is at most 1, so all three terms use the quadratic branch before averaging.

Input: y_true = [0, 5], y_pred = [2, 8], delta = 1.0

Output: 2.0

Input: y_true = [1, 2], y_pred = [1, 2], delta = 1.0

Output: 0.0

Hint 1
Compute absolute_error = np.abs(y_true - y_pred).

Hint 2
Use np.where to select the two loss branches before taking the mean.

Requirements
Apply the quadratic branch when the absolute error is at most delta
Apply the linear branch when the absolute error exceeds delta
Return the mean loss as a Python float
Constraints
y_true and y_pred are equal-length nonempty numeric lists
delta is positive
Each list contains at most 1,000,000 values
Use NumPy only

"""

import numpy as np

def huber_loss(y_true: list, y_pred: list, delta: float = 1.0) -> float:
    e = np.abs(np.array(y_true) - np.array(y_pred))
    L = np.where(e <= delta, 0.5*e**2, delta*(e - 0.5*delta))
    return np.mean(L)

def main():
    print(huber_loss([1, 2, 3], [1.5, 1.7, 2.5], 1.0))
    print(huber_loss([0, 5], [2, 8], 1.0))
    print(huber_loss([1, 2], [1, 2], 1.0))

main()

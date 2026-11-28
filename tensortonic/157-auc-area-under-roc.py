#!/usr/bin/env python3

"""

Compute the area under a ROC curve with the trapezoidal rule.
For consecutive points (xi, yi) = (FPRi, TPRi)

AUC = Sum[i=1, M-1] (x[i+1] - x[i]) * (y[i] + y[i+1]) / 2

Here, M is the number of curve points. Return the summed area as a Python float.

Examples
Input: fpr = [0, 0, 1], tpr = [0, 1, 1]

Output: 1.0

Explanation: The curve rises vertically to a true-positive rate of one before spanning the full false-positive range.

Input: fpr = [0, 1], tpr = [0, 1]

Output: 0.5

Hint 1
Hint 2
Requirements
Compute each interval width from consecutive FPR values
Multiply by the average of the neighboring TPR values
Sum all trapezoid areas
Return a Python float
Constraints
fpr and tpr have the same length of at least two
fpr is nondecreasing
Both arrays contain values between 0 and 1
Use NumPy only

"""

import numpy as np

def auc(fpr: list, tpr: list) -> float:
    area = 0.0
    for i in range(len(fpr)-1):
        area += (fpr[i+1] - fpr[i]) * (tpr[i] + tpr[i+1]) * 0.5
    return area

def main():
    print(auc([0, 0, 1], [0, 1, 1]))
    print(auc([0, 1], [0, 1]))

main()

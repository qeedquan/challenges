#!/usr/bin/env python3

"""

Compute the Euclidean distance between two equal-length vectors:

d(x, y) = sqrt(Sum[i=1, N] (x[i] - y[i])^2)

Here, N is the vector length and x[i] and y[i] are corresponding coordinates. Return the distance as a Python float.

Examples
Input: x = [3, 4], y = [0, 0]

Output: 5.0

Explanation: The squared differences are 9 and 16, so the distance is the square root of 25.

Input: x = [1, 2, 3], y = [4, 5, 6]

Output: 5.196152

Input: x = [0, 0, 0], y = [0, 0, 0]

Output: 0.0

Hint 1
difference = np.asarray(x, dtype=float) - np.asarray(y, dtype=float) forms the displacement vector.

Hint 2
np.sqrt(np.sum(difference ** 2)) computes its L2 norm.

Requirements
Convert both input lists to NumPy arrays
Compute all coordinate differences without a Python element loop
Return a Python float
Constraints
x and y are nonempty one-dimensional lists with the same length
Use NumPy only

"""

import numpy as np

def euclidean_distance(x: list, y: list) -> float:
    difference = np.asarray(x, dtype=float) - np.asarray(y, dtype=float)
    return np.sqrt(np.sum(difference**2))

def main():
    print(euclidean_distance([3, 4], [0, 0]))
    print(euclidean_distance([1, 2, 3], [4, 5, 6]))
    print(euclidean_distance([0, 0, 0], [0, 0, 0]))

main()

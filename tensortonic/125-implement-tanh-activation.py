#!/usr/bin/env python3

"""

Apply the hyperbolic tangent activation elementwise:

tanh(x) = (e^x - e^(-x)) / (e^x + e^(-x))

Here, x is each input value. Return a NumPy array with the same shape as the input and values in (-1, 1)

Examples
Input: x = [0, 1, -1, 3]

Output: [0.0, 0.761594, -0.761594, 0.995055]

Explanation: Tanh maps zero to zero and maps positive and negative inputs symmetrically toward 1 and -1.

Input: x = [[0, 1], [-1, 2]]

Output: [[0.0, 0.761594], [-0.761594, 0.964028]]

Hint 1
Convert the input with np.asarray(x, dtype=float).

Hint 2
Use NumPy's vectorized np.tanh function.

Requirements
Apply hyperbolic tangent elementwise
Preserve the input shape
Return a NumPy array of floating-point values
Constraints
x is a nonempty finite numeric list of any shape
x contains at most 1,000,000 values
Use NumPy only

"""

import numpy as np

def tanh(x: list) -> np.ndarray:
    return np.tanh(x)

def main():
    print(tanh([0, 1, -1, 3]))
    print(tanh([[0, 1], [-1, 2]]))

main()

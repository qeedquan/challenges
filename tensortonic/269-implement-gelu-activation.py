#!/usr/bin/env python3

"""

Compute the exact Gaussian Error Linear Unit for every input value:

GELU(x) = x/2 * (1 + erf(x/sqrt(2)))

Here, x is an input and erf is the Gaussian error function.
Apply the formula elementwise and return a NumPy array with the same shape as the input.

Examples
Input: x = [-1.0, 0.0, 1.0]

Output: [-0.158655, 0.0, 0.841345]

Explanation: The exact GELU formula scales negative values toward zero while retaining most of a positive value.

Input: x = [[-2.0, -1.0], [0.0, 1.0]]

Output: [[-0.0455, -0.158655], [0.0, 0.841345]]

Hint 1
Use np.asarray(x, dtype=float) before applying the formula.

Hint 2
Use np.vectorize(math.erf) to apply the scalar error function elementwise.

Requirements
Apply the exact error-function formula elementwise
Preserve the input shape
Return a NumPy array of floating-point values
Constraints
x is a nonempty finite numeric list of any depth
x contains at most 10^6 values
Use NumPy and the Python standard library only

"""

import numpy as np
from scipy import special

def gelu(x: list) -> np.ndarray:
    x = np.array(x)
    return x * 0.5 * (1 + special.erf(x / np.sqrt(2)))

def main():
    print(gelu([-1, 0, 1]))
    print(gelu([[-2, -1], [0, 1]]))

main()

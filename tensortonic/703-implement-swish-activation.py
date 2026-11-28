#!/usr/bin/env python3

"""

Apply the Swish activation elementwise:

Swish(x) = x*sigmoid(x)

sigmoid(x) = 1 / (1 + exp(-x))

Here, x is each input value and σ is the sigmoid function.
Compute sigmoid without overflow and return a NumPy array with the same shape as the input.

Examples
Input: x = [0, 1, -1, 3]

Output: [0.0, 0.731059, -0.268941, 2.857722]

Explanation: Each value is multiplied by its sigmoid gate.

Input: x = [[1, -1], [2, -2]]

Output: [[0.731059, -0.268941], [1.761594, -0.238406]]

Hint 1
Use np.exp(-np.logaddexp(0.0, -x)) for a stable sigmoid.

Hint 2
Multiply the sigmoid array elementwise by x.

Requirements
Implement sigmoid with NumPy
Avoid exponential overflow
Apply Swish elementwise and preserve shape
Return a NumPy array of floating-point values
Constraints
x is a nonempty finite numeric list of any shape
x contains at most 1,000,000 values
Use NumPy only

"""

import numpy as np

def swish(x: list) -> np.ndarray:
    x = np.array(x)
    return x * np.exp(-np.logaddexp(0.0, -x))

def main():
    print(swish([0, 1, -1, 3]))
    print(swish([[1, -1], [2, -2]]))

main()

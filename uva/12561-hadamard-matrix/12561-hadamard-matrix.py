#!/usr/bin/env python3

import numpy as np
from math import sqrt

def solve(a, b, n):
    H = 1/sqrt(2) * np.array([[1, 1], [1, -1]])
    H = np.linalg.matrix_power(H, n)
    x = np.dot(H, np.array([[a], [b]]))
    return abs(x[0])**2

def main():
    assert(np.allclose(solve(1+0j, 0+0j, 1), 0.5))
    assert(np.allclose(solve(0.017133+0.704420j, 0.410273+0.578943j, 1), 0.914848))

main()

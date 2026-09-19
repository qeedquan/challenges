#!/usr/bin/env python3

import numpy as np

def solve(a, b, m):
    X = np.array([[0, 1], [1, 1]], dtype=object)
    Y = np.array([[a], [b]], dtype=object)
    X = np.linalg.matrix_power(X, m)
    R = np.dot(X, Y)
    return R[0][0]

def main():
    assert(solve(100, 100, 50) == 2036501107400)

main()

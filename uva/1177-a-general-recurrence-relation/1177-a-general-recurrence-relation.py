#!/usr/bin/env python3

import numpy as np

def solve(f0, f1, a, b, n):
    A = np.array([[a, b], [1, 0]])
    A = np.linalg.matrix_power(A, n)
    return A[1][0]*f1 + A[1][1]*f0

def main():
    assert(solve(0, 1, 1, 1, 20) == 6765)
    assert(solve(0, 1, -1, 0, 1000000000) == -1)
    assert(solve(-1, 1, 4, -3, 18) == 387420487)

main()

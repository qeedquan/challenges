#!/usr/bin/env python3

import numpy as np

def solve(N, K, L):
    A = np.array([[K, 1], [L, 0]], dtype=object)
    A = np.linalg.matrix_power(A, N//5)
    return "%06d" % (A[0][0] % 1000000)

def main():
    assert(solve(25, 5, 5) == "006000")
    assert(solve(5, 1000, 1000) == "001000")
    assert(solve(20, 17, 31) == "111359")
    assert(solve(15, 9, 2) == "000765")

main()


#!/usr/bin/env python3

import numpy as np

def solvebf(A, k):
    M = np.zeros((len(A), len(A)))
    for i in range(1, k + 1):
        M += np.linalg.matrix_power(A, i)
    return M

"""

https://stackoverflow.com/questions/18890570/matrix-power-sum

Let

B(n) = A + ... + A^n

We have:

B(1) = A
B(n) = B(n / 2) * (I + A^(n / 2)) if n is even
B(n) = B(n / 2) * (I + A^(n / 2)) + A^n if n is odd

"""
def solve(A, k):
    n = len(A)
    if k < 1:
        return np.zeros((n, n))
    if k == 1:
        return A

    M = np.dot(solve(A, k//2), (np.eye(n) + np.linalg.matrix_power(A, k//2)))
    if k%2 != 0:
        M += np.linalg.matrix_power(A, k)
    return M

def main():
    print(solve([[0, 2, 0], [0, 0, 2], [0, 0, 0]], 2))
    
    rng = np.random.default_rng()
    for i in range(1, 100):
        for k in range(1, 20):
            A = rng.random((i, i))
            assert(np.allclose(solve(A, k), solvebf(A, k)))

main()

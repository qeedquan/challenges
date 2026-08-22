#!/usr/bin/env python3

"""

Given following expression:

M = 
a b c
d e f
g h i

det(M) = -6

N =
d e f
g h i
a b c

det(N) = ?

Find the following determinant value

"""

import numpy as np

# swapping rows flips the sign of the determinant
# since the matrix gets two rows swapped, the signed is flipped twice
# which is the same determinant as the original matrix
def solve(M):
    return np.linalg.det(M)

def swap(M):
    N = M.copy()
    N[[0, 1], :] = N[[1, 0], :]
    N[[1, 2], :] = N[[2, 1], :]
    return N

def test(M):
    N = swap(M)
    d1 = np.linalg.det(M)
    d2 = solve(N)
    assert(np.allclose(d1, d2))

def main():
    test(np.array([[2, 0, 0], [0, 3, 0], [0, 0, -1]]))
    test(np.array([[1, 2, 3], [53, 2, 50], [100, 12, 321]]))
    test(np.array([[1, 44, 321], [5, 1, 150], [10, 13, 1]]))
    test(np.array([[1, 2, 3], [4, 5, 6], [7, 8, 9]]))
    for i in range(10000):
        test(np.random.rand(3, 3))

main()

#!/usr/bin/env python3

import numpy as np
from sympy import Matrix

def solve(A, b):
    try:
        x = np.linalg.solve(A, b)
        print(x)
    except Exception as ex:
        A = Matrix(A)
        b = Matrix(b)
        M = A.row_join(b)
        if A.rank() == M.rank() and A.rank() < A.cols:
            print("Infinite many solutions containing %d arbitrary constants." % (A.cols - A.rank()))
        else:
            print("No solution.")

def main():
    A1 = [[9, 4, 1], [1, -2, -6], [1, 6, 0]]
    A2 = [[2, 2, 2], [4, 4, 4], [16, 16, 16]]
    A3 = [[1, 1], [1, 1], [2, 2]]
    A4 = [[3]]

    b1 = [-17, 14, 4]
    b2 = [2, 4, 16]
    b3 = [10, 20, 50]
    b4 = [10]

    solve(A1, b1)
    solve(A2, b2)
    solve(A3, b3)
    solve(A4, b4)

main()


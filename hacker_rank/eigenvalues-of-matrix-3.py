#!/usr/bin/env python3

"""

Find the eigenvalues of A and A2 where A is

A = 2 -1
   -1  2

Your answer should have the eigenvalues of A followed by eigenvalues of A2 separated by a single line resembling this(with smaller value coming first):
5
6
2
3

"""

import numpy as np

def main():
    A = np.array([[2, -1], [-1, 2]])
    A2 = np.dot(A, A)
    ev, _ = np.linalg.eig(A)
    ev2, _ = np.linalg.eig(A2)
    print(ev)
    print(ev2)

main()

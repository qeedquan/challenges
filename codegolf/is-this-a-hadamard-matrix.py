#!/usr/bin/env python3

"""

Hadamard matrices is a square matrix whose entries are either +1 or −1 and whose rows are mutually orthogonal.

In other words, it means that each pair of rows has matching entries in exactly half of their columns and mismatched entries in the remaining columns. As a result, the same properties hold for columns as well as rows.

Examples
[ 1  1  1  1
  1 -1  1 -1
  1  1 -1 -1
  1 -1 -1  1 ]
This is a Hadamard matrix, because any pair of rows has matching entries in exactly half of their columns, like:

[ 1  1  1  1
  |  /  |  /
  1 -1  1 -1
             ]
There are 2 |s (matching entries) and 2 /s (mismatched entries). The same logic also applies by columns:

[ 1  ―  1
  1  ―  1
  1  ~ -1
  1  ~ -1    ]
There are two ―s (matching entries) and two ~s (mismatched entries).

This logic can be applied to every pair of rows and columns.

Another example:

[ 1  1
  1 -1 ]
This is a hadamard matrix, because there is only one pair of rows and one pair of columns, but their matching entries is still half of the size of the matrix.

A counterexample like:

[  1 -1  1 -1
  -1  1 -1  1
   1 -1  1 -1
  -1  1 -1  1 ]
is not a Hadamard matrix, because two pair of rows match in all columns, and four rows don't match in any column. The same logic applies to pair of columns.

Note that

[ 1 ]
is also a Hadamard (1x1) matrix, and your code should handle that (See challenge).

Notes
The matrix inputs are always square

The matrix will only contain -1 or 1. No zeros.

Challenge
The shortest answer that checks if a matrix is a Hadamard matrix wins, because this is code-golf. You may not take input as 1d array, it must be 2d array if your language has a builtin 2d arrays.

"""

import numpy as np

"""

A hadamard matrix satisfies the following properties:

A nxn square matrix with all entries being +1/-1
H*tranpose(H) = n*identity(n)

"""

def hadamard(H):
    if len(H) == 0 or len(H[0]) == 0:
        return True
    if len(H) != len(H[0]):
        return False

    n = len(H)
    for i in range(n):
        for j in range(n):
            if abs(H[i][j]) != 1:
                return False

    A = np.dot(H, np.transpose(H))
    B = n * np.eye(n)
    return np.allclose(A, B)

def main():
    assert(hadamard(np.array([[1, 1, 1, 1], [1, -1, 1, -1], [1, 1, -1, -1], [1, -1, -1, 1]])) == True)
    assert(hadamard(np.array([[1, -1, 1, -1], [-1, 1, -1, 1], [1, -1, 1, -1], [-1, 1, -1, 1]])) == False)
    assert(hadamard(np.array([[1]])) == True)

main()

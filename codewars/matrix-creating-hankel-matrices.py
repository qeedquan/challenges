#!/usr/bin/env python3

"""

The Catalan Numbers are defined by the formula:

Cn = 1 / (n + 1) * binomial(2n, n)

The first nine Catalan Numbers are:

Catalan Number    Ordinal Term
1                      0
1                      1
2                      2
5                      3
14                     4
42                     5
132                    6
429                    7
1430                   8
The Hankel Matrix is filled with the Catalan Numbers repeating the same term along the diagonals that have the direction UP-RIGHT to DOWN-LEFT, and have a courious property, its determinant is equal to 1. The following is a 4 x 4 Hankel matrix, and as we said before, its determinant value equals to 1.

The task for this kata is to create a code that may build a Hankel Matrix with the distribution of terms given above. For more information about Catalan Numbers and the Hankel Matrix you may check at Wikipedia, Here.

Features of the random Tests:

number of tests = 80
2 <= n <= 100  // n, dimension of the matrix

"""

import math

def catalan(n):
    return math.comb(2*n, n) // (n+1)

def hankel(n):
    m = []
    for i in range(n):
        p = []
        for j in range(n):
            p.append(catalan(i + j))
        m.append(p)
    return m

def main():
    assert(hankel(4) == [[1, 1, 2, 5], [1, 2, 5, 14], [2, 5, 14, 42], [5, 14, 42, 132]])
    assert(hankel(2) == [[1, 1], [1, 2]])

main()

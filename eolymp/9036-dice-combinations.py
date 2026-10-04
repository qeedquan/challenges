#!/usr/bin/env python3

"""

Your task is to count the number of ways to construct sum n by throwing a dice one or more times.
Each throw produces an outcome between 1 and 6.

For example, if n=3, there are 4 ways:

1+1+1

1+2

2+1

3

Input
One integer n (1≤n≤10^6).

Output
Print the number of ways modulo 10^9+7.

Examples

Input #1
3

Answer #1
4

Input #4
4

Answer #4
8

Input #5
5

Answer #5
16

Input #7
7

Answer #7
63

"""

import numpy as np

# https://oeis.org/A001592
def hexanacci(n):
    if n < 0:
        return 0

    A = np.array([
        [1, 1, 1, 1, 1, 1],
        [1, 0, 0, 0, 0, 0],
        [0, 1, 0, 0, 0, 0],
        [0, 0, 1, 0, 0, 0],
        [0, 0, 0, 1, 0, 0],
        [0, 0, 0, 0, 1, 0],
    ], dtype=object)

    A = np.linalg.matrix_power(A, n)
    return A[0][0]

def main():
    tab = [
        0, 0, 0, 0, 0, 1, 1, 2, 4, 8, 16, 32, 63, 125, 248, 492, 976, 1936,
        3840, 7617, 15109, 29970, 59448, 117920, 233904, 463968, 920319, 1825529,
        3621088, 7182728, 14247536, 28261168, 56058368, 111196417, 220567305,
        437513522, 867844316, 1721441096, 3414621024
    ]

    assert(hexanacci(3) == 4)
    assert(hexanacci(4) == 8)
    assert(hexanacci(5) == 16)
    assert(hexanacci(7) == 63)

    for i in range(len(tab)):
        assert(hexanacci(i - 5) == tab[i])

main()

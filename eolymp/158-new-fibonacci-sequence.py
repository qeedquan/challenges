#!/usr/bin/env python3

"""

A new Fibonacci sequence is defined as follows: the first four terms are all equal to one, and each subsequent term is the sum of the four preceding terms.

Input
The first line contains the integer T (1≤T≤1000), the number of test cases.
The next line contains T integers — the indices of the terms in the sequence you need to find.

Output
Output T lines, each containing the specified term of the new sequence.

The number of digits in each term does not exceed 2008.

Examples

Input #1
3
3
6
9

Answer #1
1
7
49

"""

import numpy as np

def tetranaccibf(n):
    if n < 0:
        return 0

    a, b, c, d = 1, 1, 1, 1
    for i in range(n - 1):
        a, b, c, d = b, c, d, a + b + c + d
    return a

# https://oeis.org/A000288
def tetranacci(n):
    if n < 0:
        return 0

    x = np.array([1, 1, 1, 1], dtype=object)
    if n > 4:
        A = np.array([[1, 1, 1, 1], [1, 0, 0, 0], [0, 1, 0, 0], [0, 0, 1, 0]], dtype=object)
        A = np.linalg.matrix_power(A, n - 4)
        x = np.dot(A, x)
    return x[0]

def main():
    tab = [
        1, 1, 1, 1, 4, 7, 13, 25, 49, 94, 181, 349, 673, 1297, 2500, 4819, 9289,
        17905, 34513, 66526, 128233, 247177, 476449, 918385, 1770244, 3412255,
        6577333, 12678217, 24438049, 47105854, 90799453, 175021573, 337364929,
        650291809, 1253477764
    ]

    assert(tetranacci(3) == 1)
    assert(tetranacci(6) == 7)
    assert(tetranacci(9) == 49)

    for i in range(len(tab)):
        assert(tetranacci(i + 1) == tab[i])

    for i in range(100):
        assert(tetranacci(i) == tetranaccibf(i))

main()


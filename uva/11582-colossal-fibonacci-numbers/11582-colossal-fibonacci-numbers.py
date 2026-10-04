#!/usr/bin/env python3

from sympy import factorint
from functools import reduce
from math import lcm
import numpy as np

# https://oeis.org/A001175
def pisano(n):
    if n < 1:
        return 0
    if n == 1:
        return 1

    f = factorint(n)
    if len(f) > 1:
        return reduce(lcm, (pisano(a**f[a]) for a in f))

    k, x = 1, [1, 1]
    while x != [0, 1]:
        k += 1
        x = [x[1], (x[0] + x[1]) % n]
    return k

def solve(a, b, n):
    m = pow(a, b, pisano(n))
    A = np.array([[1, 1], [1, 0]], dtype=object)
    A = np.linalg.matrix_power(A, m)
    return A[1][0] % n

def main():
    assert(solve(1, 1, 2) == 1)
    assert(solve(2, 3, 1000) == 21)
    assert(solve(18446744073709551615, 18446744073709551615, 1000) == 250)

main()

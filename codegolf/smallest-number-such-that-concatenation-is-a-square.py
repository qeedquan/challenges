#!/usr/bin/env python3

"""

Challenge
Write a program or function that takes a number n and returns the smallest k such that concatenation n′k is a square. This sequence is described by A071176 on the OEIS.

I/O Examples
input --> output

1   -->    6 (4^2)
10  -->    0 (10^2)
35  -->  344 (188^2)
164 -->  836 (406^2)
284 --> 2596 (1686^2)

Rules
Input will always be a positive decimal integer
Output will be a positive decimal integer with no leading 0's or 0
Standard I/O rules apply
No standard loopholes
This is code-golf, so shortest code in bytes wins

"""

from math import isqrt
from sympy.ntheory.primetest import is_square

# https://oeis.org/A071176
def seq(n):
    m = 10 * n
    if is_square(m):
        return 0

    k = 0
    a = 1
    while True:
        k = (isqrt(a*(m+1)-1)+1)**2 - m*a
        if k < 10*a:
            break
        a *= 10
    return k

def main():
    tab = [
        6, 5, 6, 9, 29, 4, 29, 1, 61, 0, 56, 1, 69, 4, 21, 9, 64, 49, 6, 25, 16,
        5, 104, 336, 6, 244, 225, 9, 16, 25, 36, 4, 64, 81, 344, 1, 21, 44, 69,
        0, 209, 25, 56, 1, 369, 24, 61, 4, 284, 41, 84, 9, 29, 76, 225, 25, 6,
        564, 29, 84, 504, 5, 504
    ]

    for i in range(len(tab)):
        assert(seq(i + 1) == tab[i])

    assert(seq(1) == 6)
    assert(seq(10) == 0)
    assert(seq(35) == 344)
    assert(seq(164) == 836)
    assert(seq(284) == 2596)

main()

#!/usr/bin/env python3

"""

Example

Input: 10
Output: 27
10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800, and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 = 27

You can expect the input to be an integer above 0. Output can be of any type, but the answer should be in the standard base of the coding language.

Test cases:

10    27
19    45
469   4140
985   10053
N.B. Some languages can not support large numbers above 32-bit integers; for those languages you will not be expected to calculate large factorials.

OEIS link here thanks to Martin Ender

This is code-golf, so shortest code in characters wins!

"""

from math import factorial

# https://oeis.org/A004152
def dsf(n):
    r = 0
    n = factorial(n)
    while n > 0:
        r += n % 10
        n //= 10
    return r

def main():
    tab = [
        1, 1, 2, 6, 6, 3, 9, 9, 9, 27, 27, 36, 27, 27, 45, 45, 63, 63, 54, 45,
        54, 63, 72, 99, 81, 72, 81, 108, 90, 126, 117, 135, 108, 144, 144, 144,
        171, 153, 108, 189, 189, 144, 189, 180, 216, 207, 216, 225, 234, 225,
        216, 198, 279, 279, 261, 279, 333, 270, 288
    ]

    for i in range(len(tab)):
        assert(dsf(i) == tab[i])

main()

#!/usr/bin/env python3

"""

The Lehmer-Comtet sequence is a sequence such that a(n) is the nth derivative of f(x) = x^x with respect to x as evaluated at x = 1.

Task
Take a non-negative integer as input and output the nth term of the Lehmer-Comtet sequence.

This is code-golf so you should minimize the file size of your source code.

Test Cases
OEIS 5727

Here are the first couple terms in order (copied from the OEIS)

1, 1, 2, 3, 8, 10, 54, -42, 944, -5112, 47160, -419760, 4297512, -47607144, 575023344, -7500202920, 105180931200, -1578296510400, 25238664189504, -428528786243904, 7700297625889920, -146004847062359040, 2913398154375730560, -61031188196889482880

"""

from sympy import *

# https://oeis.org/A005727
def lc(n):
    d = diff('x^x', 'x', n)
    r = d.subs('x', 1)
    return r

def main():
    tab = [1, 1, 2, 3, 8, 10, 54, -42, 944, -5112, 47160, -419760, 4297512, -47607144, 575023344, -7500202920, 105180931200, -1578296510400, 25238664189504, -428528786243904, 7700297625889920, -146004847062359040, 2913398154375730560, -61031188196889482880]

    for i in range(len(tab)):
        assert(lc(i) == tab[i])

main()

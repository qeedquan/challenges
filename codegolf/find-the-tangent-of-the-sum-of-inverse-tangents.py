#!/usr/bin/env python3

"""

Background
It can be shown that for any integer k >= 0, f(k) = tan(atan(0) + atan(1) + atan(2) + ... + atan(k)) is a rational number.

Goal
Write a complete program or function which when given k >= 0, outputs f(k) as a single reduced fraction (the numerator and denominator are coprime).

Test cases
The first few values are

f(0) = (0,1)
f(1) = (1,1)
f(2) = (-3,1)
f(3) = (0,1)
f(4) = (4,1)
f(5) = (-9,19)
f(6) = (105,73)

Rules
Standard loopholes are forbidden.
Input and output may be in any convenient format. You may output f(k) as a string numerator/denominator, as a tuple of two integers, a fraction or rational object, etc. If you output a string, give two integers only, that is, output 3/2 instead of 1 1/2.
This is code-golf, the shortest answer (in bytes) wins.

"""

from fractions import *

"""

@tsh

Use the identity:

tan(A + B) = (tan(A) + tan(B)) / (1 - tan(A) * tan(B))

We have:

f(k) = 0                                    if k = 0
     = (k + f(k - 1)) / (1 - k * f(k - 1))  if k > 0

"""
def f(k):
    if k < 1:
        return 0
    return Fraction((k + f(k-1)) / (1 - k*f(k-1)))

def main():
    assert(f(0) == Fraction(0, 1))
    assert(f(1) == Fraction(1, 1))
    assert(f(2) == Fraction(-3, 1))
    assert(f(3) == Fraction(0, 1))
    assert(f(4) == Fraction(4, 1))
    assert(f(5) == Fraction(-9, 19))
    assert(f(6) == Fraction(105, 73))

main()

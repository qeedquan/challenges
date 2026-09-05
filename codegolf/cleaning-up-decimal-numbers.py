#!/usr/bin/env python3

"""

Background
Sometimes in calculus you're expected to calculate the sum of an infinite series. Sometimes these series are very friendly, like a geometric series, but add anything else onto it and it can quickly get complicated to solve by hand.

Sometimes I like to be lazy - a lot of sums can be found simply by adding the first few terms then making an approximation. Say the sum of the first ten terms is 0.199999983, and the future terms are approaching zero. We can say with a fair degree of certainty that our final answer will be 0.2, or 1/5.

The Challenge
Given a decimal number and an integer as inputs, calculate the best (fully simplified) fractional approximation of the decimal number for all fractions up to a denominator of the given integer. The best fractional approximation will be that which is closest to the decimal number in absolute value.

You may take these inputs any way you like and you may output the numerator and denominator any way you like. The numerator and denominator must always be integers, and you may assume we will deal with only positive numbers because adding a negative sign is trivial.

Test Cases
Input | Output

1.21, 8 | 6/5

3.14159265359, 1000000 | 3126535/995207

19.0, 10000000 | 19/1

3.14159265359, 12 | 22/7

2.7182818, 100 | 193/71

0.8193927511, 22 | 9/11

0.2557463559, 20 | 1/4

0.2557463559, 100 | 11/43

0.0748947977, 225 | 14/187
Scoring
This is code-golf. Shortest code wins!

"""

from fractions import *

def cf(x, n):
    f = Fraction(x)
    return f.limit_denominator(n)

def main():
    assert(cf(1.21, 8) == Fraction(6, 5))
    assert(cf(3.14159265359, 1000000) == Fraction(3126535, 995207))
    assert(cf(19.0, 10000000) == Fraction(19, 1))
    assert(cf(3.14159265359, 12) == Fraction(22, 7))
    assert(cf(2.7182818, 100) == Fraction(193, 71))
    assert(cf(0.8193927511, 22) == Fraction(9, 11))
    assert(cf(0.2557463559, 20) == Fraction(1, 4))
    assert(cf(0.2557463559, 100) == Fraction(11, 43))
    assert(cf(0.0748947977, 225) == Fraction(14, 187))

main()

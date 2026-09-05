#!/usr/bin/env python3

"""

There exists an equation, assuming n and x are positive,

i = n*x^n = (n*x)^n / (n^(n-1))

that expresses the relationship between two monomials, one being a common misrepresentation of the other. Many people make the simple mistake of equating these (i.e. 3x^2 and (3x)^2).

Challenge
Given a positive integer, i, determine and return the solution n and x with the smallest sum as an array [n, x]. In the case of a tie, any solution set is acceptable.

Test Cases
62658722541234765
[15, 11]

202500
[4, 15]

524288
[8, 4]

33044255768277
[13, 9]

"""

from sympy import divisors

"""

@miles

Given i, computes the divisors of i to generate pairs of [n, x] where n is a divisor and x = floor( (i/n)^(1/n) ).
Then filters it for values where n * x^n == i, sort the remaining pairs by their sum, and returns the first pair.

"""

def mispoly(i):
    r = (-1, -1)
    m = 0
    for n in divisors(i):
        x = int((i/n)**(1/n))
        if n*x**n == i and (m == 0 or m > n + x):
            r = (n, x)
            m = n + x
    return r

def main():
    assert(mispoly(62658722541234765) == (15, 11))
    assert(mispoly(202500) == (4, 15))
    assert(mispoly(524288) == (8, 4))
    assert(mispoly(33044255768277) == (13, 9))

main()

#!/usr/bin/env python3

"""

Definitions
An algebraic number is a number that is a zero of a non-zero polynomial with integer coefficients. For example, the square root of 2 is algebraic, because it is a zero of x^2 - 2.
The corresponding polynomial is called the minimal polynomial of the algebraic number, provided that the polynomial is irreducible over ℚ.

Task
Given the minimal polynomials of two algebraic numbers, construct a set of numbers that are the sum of two numbers, one from the root of one polynomial, and one from the other.
Then, construct a polynomial having those numbers as roots. Output the polynomial. Note that all roots are to be used, including complex roots.

Example
The two roots of x^2-2 are √2 and -√2.
The two roots of x^2-3 are √3 and -√3.
Pick one from a polynomial, one from the other, and form 4 sums: √2+√3, √2-√3, -√2+√3, -√2-√3.
A polynomial containing those four roots is x^4-10x^2+1

Input
Two polynomials in any reasonable format (e.g. list of coefficients). They will have degree at least 1.

Output
One polynomial in the same format, with integer coefficients.

You are not required to output an irreducible polynomial over ℚ.

Testcases
Format: input, input, output.

x^4 - 10 x^2 + 1
x^2 + 1
x^8 - 16 x^6 + 88 x^4 + 192 x^2 + 144

x^3 - 3 x^2 + 3 x - 4
x^2 - 2
x^6 - 6 x^5 + 9 x^4 - 2 x^3 + 9 x^2 - 60 x + 50

4x^2 - 5
2x - 1
x^2 - x - 1

2x^2 - 5
2x - 1
4x^2 - 4 x - 9

x^2 - 2
x^2 - 2
x^3 - 8 x
The outputs are irreducible over ℚ here. However, as stated above, you do not need to output irreducible polynomials over ℚ.

Scoring
This is code-golf. Shortest answer in bytes wins.

"""

from sympy import *
from sympy.abc import *

def combine(p0, p1):
    r0 = list(roots(p0))
    r1 = list(roots(p1))

    m = {}
    p = 1
    for c0 in r0:
        for c1 in r1:
            c = c0 + c1
            if c not in m:
                p *= (x - c)
                m[c] = True

    return expand(simplify(p))

def main():
    assert(combine(x**2 - 2, x**2 - 3) == (x**4 - 10*x**2 + 1))
    assert(combine(x**4 - 10*x**2 + 1, x**2 + 1) == (x**8 - 16*x**6 + 88*x**4 + 192*x**2 + 144))
    assert(combine(x**3 - 3*x**2 + 3*x - 4, x**2 - 2) == (x**6 - 6*x**5 + 9*x**4 - 2*x**3 + 9*x**2 - 60*x + 50))
    assert(combine(4*x**2 - 5, 2*x - 1) == (x**2 - x - 1))
    assert(combine(2*x**2 - 5, 2*x - 1)*4 == (4*x**2 - 4*x - 9))
    assert(combine(x**2 - 2, x**2 - 2) == (x**3 - 8*x))

main()

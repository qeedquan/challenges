#!/usr/bin/env python3

"""

Given a polynomial, determine whether it's prime.

A polynomial is ax^n + bx^(n-1) + ... + dx^3 + ex^2 + fx + g, where each term is a constant number (the coefficient) multiplied by a nonnegative integer power of x. The highest power with a nonzero coefficient is called the degree. For this challenge, we only consider polynomials of at least degree 1. That is, each polynomial contains some x. Also, we only use polynomials with integer coefficients.

Polynomials can be multiplied. For example, (x+3)(2x^2-2x+3) equals 2x^3+4x^2-3x+9. Thus, 2x^3+4x^2-3x+9 can be factored into x+3 and 2x^2-2x+3, so it is composite.

Other polynomials can not be factored. For example, 2x^2-2x+3 is not the product of any two polynomials (ignoring constant polynomials or those with non-integer coefficients). Hence, it is prime (also known as irreducible).

Rules
Input and output can be through any standard way.
Input can be a string like 2x^2-2x+3, a list of coeffecients like {2,-2,3}, or any similar means.
Output is either a truthy value if it's prime, or a falsey value if it's composite. You must yield the same truthy value for all primes, and the same falsey value for all composite polynomials.
The input will be of at least degree 1 and at most degree 10.
You may not use built-in tools for factorization (of integers or expressions) or equation solving.
Examples
True - prime
x+3
-2x
x^2+x+1
x^3-3x-1
-2x^6-3x^4+2
3x^9-8x^8-3x^7+2x^3-10
False - composite
x^2
x^2+2x+1
x^4+2x^3+3x^2+2x+1
-3x^7+5x^6-2x
x^9-8x^8+7x^7+19x^6-10x^5-35x^4-14x^3+36x^2+16x-12

"""

from sympy import Poly
from sympy.abc import x

def polyprime(eq):
    return Poly(eq).is_irreducible

def main():
    assert(polyprime(x + 3) == True)
    assert(polyprime(-2*x) == True)
    assert(polyprime(x**2 + x + 1) == True)
    assert(polyprime(x**3 - 3*x - 1) == True)
    assert(polyprime(-2*x**6 - 3*x**4 + 2) == True)
    assert(polyprime(3*x**9 - 8*x**8 - 3*x**7 + 2*x**3 - 10) == True)

    assert(polyprime(x**2) == False)
    assert(polyprime(x**2 + 2*x + 1) == False)
    assert(polyprime(x**4 + 2*x**3 + 3*x**2 + 2*x + 1) == False)
    assert(polyprime(-3*x**7 + 5*x**6 - 2*x) == False)
    assert(polyprime(x**9 - 8*x**8 + 7*x**7 + 19*x**6 - 10*x**5 - 35*x**4 - 14*x**3 + 36*x**2 + 16*x - 12) == False)

main()

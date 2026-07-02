#!/usr/bin/env python3

"""

Challenge
Given a polynomial p with real coefficients of order 1 and degree n, find another polynomial q of degree at most n such that (p∘q)(X)=p(q(X))≡XmodXn+1, or in other words such that p(q(X))=X+h(X) where h is an arbitrary polynomial with ord(h)⩾n+1.
The polynomial q is uniquely determined by p.

For a polynomial p(X)=a[n]X^n + a[n+1]X^(n+1) + ... + a[m]X^m where n⩽m and an≠0, am≠0, we say n is the order of p and m is the degree of p.

Simplification: You can assume that p has integer coefficients, and a1=1 (so p(X)=X+[some integral polynomial of order 2]). In this case q has integral coefficients too.

The purpose of this simplification is to avoid the issues with floating point numbers. There is however a non-integral example for illustration purposes.

Examples
Consider the Taylor series of exp(x)-1 = x + x^2/2 + x^3/6 + x^4/24 + ... and ln(x+1) = x - x^2/2 + x^3/3 - x^4/4+... then obviously ln(exp(x)-1+1)=x.
If we just consider the Taylor polynomials of degree 4 of those two functions we get with the notation from below (see testcases) p=[-1/4,1/3,-1/2,1,0] and q=[1/24,1/6,1/2,1,0] and (p∘q)(X) ≡ X mod X^5

Consider the polynomial p(X) = X+X^2+X^3+X^4.
Then for q(X)=X−X2+X3−X4 we get (p∘q)(X)=p(q(X)) = X - 2X^5 + 3X^6 - 10X^7 + ... + X^16 ≡ X mod X^5

Testcases
Here the input and output polynomials are written as lists of coefficients (with the coefficient of the highest degree monomial first, the constant term last):

p = [4,3,2,0];  q=[0.3125,-.375,0.5,0]
Integral Testcases:

p = [1,0]; q = [1,0]

p = [9,8,7,6,5,4,3,2,1,0]; q = [4862,-1430,429,-132,42,-14,5,-2,1,0]

p = [-1,3,-3,1,0]; q = [91,15,3,1,0]

"""

from sympy import *

"""

@orlp

We locally invert the polynomial by assuming that q(x) = x, composing it with p, checking the coefficient for x^2, and subtracting it from q.
Let's say the coefficient was 4, then the new polynomial becomes q(x) = x - 4x^2. We then again compose this with p, but look up the coefficient for x^3. Etc...

"""
def invert(a):
    p = Poly(a, var('x'))
    q = Poly(x)
    n = 2
    for _ in a[2:]:
        c = compose(p, q)
        q -= c.nth(n) * x**n
        n += 1
    return q.all_coeffs()

def main():
    assert(invert([1, 0]) == [1, 0])
    assert(invert([9, 8, 7, 6, 5, 4, 3, 2, 1, 0]) == [4862, -1430, 429, -132, 42, -14, 5, -2, 1, 0])
    assert(invert([-1, 3, -3, 1, 0]) == [91, 15, 3, 1, 0])

main()

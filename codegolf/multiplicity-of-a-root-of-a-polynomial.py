#!/usr/bin/env python3

"""

Let p(x) be a polynomial. We say a is a root of multiplicity k of p(x), if there is another polynomial s(x) such that p(x)=s(x)(x−a)k and s(a)≠0.

For example, the polynomial p(x)=x^3 + 2x^2 - 7x + 4 = (x+4)*(x-1)*2 has 1 and -4 as roots. 1 is a root of multiplicity 2. -4 is a root of multiplicity 1.

Task
Given a nonzero polynomial p(x) and a root a of it, find the multiplicity of a.

The coefficients of p(x) are all integers. a is also an integer.

You may take the polynomial in any reasonable format. For example, the polynomial x^4 - 4x^3 + 5x^2 - 2x may be represented as:

a list of coefficients, in descending order: [1,-4,5,-2,0];
a list of coefficients, in ascending order:[0,-2,5,-4,1];
a string representation of the polynomial, with a chosen variable, e.g., x: "x^4-4*x^3+5*x^2-2*x";
a built-in polynomial object, e.g., x^4-4*x^3+5*x^2-2*x in PARI/GP.
When you take input as a list of coefficients, you may assume that the leading coefficient (the first one in descending order) is nonzero.

This is code-golf, so the shortest code in bytes wins.

Testcases
Here I use coefficient lists in descending order:

[1,2,-7,4], 1 -> 2
[1,2,-7,4], -4 -> 1
[1,-4,5,-2,0], 0 -> 1
[1,-4,5,-2,0], 1 -> 2
[1,-4,5,-2,0], 2 -> 1
[4,0,-4,4,1,-2,1], -1 -> 2
[1,-12,60,-160,240,-192,64,0], 2 -> 6

"""

from sympy import *
from sympy.abc import x

def multiplicity(c, a):
    p = Poly.from_list(c, x)
    r = roots(p)
    m = 0
    try:
        m = r[a]
    except:
        pass
    return m

def main():
    assert(multiplicity([1, 2, -7, 4], 1) == 2)
    assert(multiplicity([1, 2, -7, 4], -4) == 1)
    assert(multiplicity([1, -4, 5, -2, 0], 0) == 1)
    assert(multiplicity([1, -4, 5, -2, 0], 1) == 2)
    assert(multiplicity([1, -4, 5, -2, 0], 2) == 1)
    assert(multiplicity([4, 0, -4, 4, 1, -2, 1], -1) == 2)
    assert(multiplicity([1, -12, 60, -160, 240, -192, 64, 0], 2) == 6)

main()

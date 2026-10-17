#!/usr/bin/env python3

"""

The resultant of two polynomials is a polynomial in their coefficients that is zero if and only if p and q have a common root.
It is a useful tool for eliminating variables from systems of polynomial equations.
For example, it is used in my answer to the code golf challenge Add up two algebraic numbers.

The resultant of two polynomials p(x) and q(x) is defined as the determinant of the Sylvester matrix.
More precisely, if p(x) = a[n]x^n + a[n-1]x^(n-1) + ... + a[0] and q(x) = b[m]x^m + b[m-1]x^(m-1) + ... b[0], then the Sylvester matrix is the following (n+m)*(n+m) matrix:
where the first m rows are the coefficients of p(x) and the last n rows are the coefficients of q(x). The resultant is the determinant of this matrix.

For example, the resultant of p(x) = x^3 + 2^x2 + 3x + 4 and q(x) = 5x^2 + 6x + 7 is the determinant of 

1 2 3 4 0
0 1 2 3 4
5 6 7 0 0
0 5 6 7 0
0 0 5 6 7

Which is equal to 832.

Task
Given two nonzero polynomials p(x) and q(x), compute their resultant.

The coefficients of the polynomials are all integers.

You may take the polynomial in any reasonable format. For example, the polynomial x^4 - 4x^3 + 5x^2 - 2x may be represented as:

a list of coefficients, in descending order: [1,-4,5,-2,0];
a list of coefficients, in ascending order:[0,-2,5,-4,1];
a string representation of the polynomial, with a chosen variable, e.g., x: "x^4-4*x^3+5*x^2-2*x";
a built-in polynomial object, e.g., x^4-4*x^3+5*x^2-2*x in PARI/GP.
When you take input as a list of coefficients, the leading coefficient is guaranteed to be nonzero.

This is code-golf, so the shortest code in bytes wins.

Test cases
Here I use coefficient lists in descending order:

[1] [2] -> 1
[3,3] [1,2,1] -> 0
[1,3,3,1] [1,0,-1] -> 0
[1,2,3,4] [5,6,7] -> 832
[1,-4,5,-2,0] [1,-4,5,-2,1] -> 1
[1,-4,5,-2,0] [1,-12,60,-160,240,-192,64,0] -> 0

"""

from sympy import *
from sympy.abc import *

def main():
    assert(resultant(Poly([1], x), Poly([2], x)) == 1)
    assert(resultant(Poly([3, 3], x), Poly([1, 2, 1], x)) == 0)
    assert(resultant(Poly([1, 3, 3, 1], x), Poly([1, 0, -1], x)) == 0)
    assert(resultant(Poly([1, 2, 3, 4], x), Poly([5, 6, 7], x)) == 832)
    assert(resultant(Poly([1, -4, 5, -2, 0], x), Poly([1, -4, 5, -2, 1], x)) == 1)
    assert(resultant(Poly([1, -4, 5, -2, 0], x), Poly([1, -12, 60, -160, 240, -192, 64, 0], x)) == 0)

main()

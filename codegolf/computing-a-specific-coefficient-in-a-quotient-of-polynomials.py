#!/usr/bin/env python3

"""

Context

After "Computing a specific coefficient in a product of polynomials", asking you to compute a specific coefficient of polynomial multiplication, I wish to create a "mirror" challenge, asking you to compute a specific coefficient from polynomial division.

Polynomial division
Let us establish an analogy with integer division. If you have two integers a and b, then there is a unique way of writing a = qb + r, with q, r integers and 0 <= r < b.

Let p(x), a(x) be two polynomials. Then there is a unique way of writing a(x) = q(x)p(x) + r(x), where q(x), r(x) are two polynomials and the degree of r(x) is strictly less than the degree of p(x).

Algorithm

Polynomial division can be performed through an iterative algorithm:

Initialize the quotient at q(x) = 0
While the degree of a(x) is at least as big as the degree of p(x):
let n = degree(a) - degree(p), let A be the coefficient of the term of highest degree in a(x) and P be the coefficient of highest degree in p(x).
do q(x) = q(x) + (A/P)x^n
update a(x) = a(x) - p(x)(A/P)x^n
q(x) is the quotient and what is left at a(x) is the remainder, which for our case will always be 0.

Task
Given two polynomials a(x), p(x) such that there exists q(x) satisfying a(x) = p(x)q(x) (with all three polynomials having integer coefficients), find the coefficient of q(x) of degree k.

(Yes, we are assuming the remainder is 0)

Input
Two polynomials (with integer coefficients) and an integer.

Each input polynomial can be in any sensible format. A few suggestions come to mind:

A string, like "1 + 3x + 5x^2"
A list of coefficients where index encodes exponent, like [1, 3, 5]
A list of (coefficient, exponent) pairs, like [(1, 0), (3, 1), (5, 2)]
An input format must be sensible AND completely unambiguous over the input space.

The integer k is a non-negative integer. You may take it in any of the usual ways. You can assume k is less than or equal to the differences of the degrees of a(x) and p(x), i.e. k <= deg(a) - deg(p) and you can assume deg(a) >= deg(p).

Output
The integer corresponding to the coefficient of x^k in the polynomial q(x) that satisfies the equality a(x) = q(x)p(x).

Test cases
The input order for the test cases is a(x), p(x), integer k.

[12], [4], 0 -> 3
[0, 0, 6], [0, 3], 0 -> 0
[0, 0, 6], [0, 3], 1 -> 2
[0, 70, 70, 17, 70, 61, 6], [0, 10, 10, 1], 0 -> 7
[0, 70, 70, 17, 70, 61, 6], [0, 10, 10, 1], 1 -> 0
[0, 70, 70, 17, 70, 61, 6], [0, 10, 10, 1], 2 -> 1
[0, 70, 70, 17, 70, 61, 6], [0, 10, 10, 1], 3 -> 6
[0, -50, 20, -35, -173, -80, 2, -9, -10, -1], [0, 10, 10, 1], 0 -> -5
[0, -50, 20, -35, -173, -80, 2, -9, -10, -1], [0, 10, 10, 1], 1 -> 7
[0, -50, 20, -35, -173, -80, 2, -9, -10, -1], [0, 10, 10, 1], 2 -> -10
[0, -50, 20, -35, -173, -80, 2, -9, -10, -1], [0, 10, 10, 1], 3 -> -8
[0, -50, 20, -35, -173, -80, 2, -9, -10, -1], [0, 10, 10, 1], 4 -> 1
[0, -50, 20, -35, -173, -80, 2, -9, -10, -1], [0, 10, 10, 1], 5 -> 0
[0, -50, 20, -35, -173, -80, 2, -9, -10, -1], [0, 10, 10, 1], 6 -> -1
This is code-golf so shortest submission in bytes, wins! If you liked this challenge, consider upvoting it... And happy golfing!

(This is not part of the RGS Golfing Showdown)

"""

from numpy.polynomial import polynomial

def coeff(a, p, k):
    (q, _) = polynomial.polydiv(a, p)
    return int(q[k])

def main():
    assert(coeff([12], [4], 0) == 3)
    assert(coeff([0, 0, 6], [0, 3], 0) == 0)
    assert(coeff([0, 0, 6], [0, 3], 1) == 2)
    assert(coeff([0, 70, 70, 17, 70, 61, 6], [0, 10, 10, 1], 0) == 7)
    assert(coeff([0, 70, 70, 17, 70, 61, 6], [0, 10, 10, 1], 1) == 0)
    assert(coeff([0, 70, 70, 17, 70, 61, 6], [0, 10, 10, 1], 2) == 1)
    assert(coeff([0, 70, 70, 17, 70, 61, 6], [0, 10, 10, 1], 3) == 6)
    assert(coeff([0, -50, 20, -35, -173, -80, 2, -9, -10, -1], [0, 10, 10, 1], 0) == -5)
    assert(coeff([0, -50, 20, -35, -173, -80, 2, -9, -10, -1], [0, 10, 10, 1], 1) == 7)
    assert(coeff([0, -50, 20, -35, -173, -80, 2, -9, -10, -1], [0, 10, 10, 1], 2) == -10)
    assert(coeff([0, -50, 20, -35, -173, -80, 2, -9, -10, -1], [0, 10, 10, 1], 3) == -8)
    assert(coeff([0, -50, 20, -35, -173, -80, 2, -9, -10, -1], [0, 10, 10, 1], 4) == 1)
    assert(coeff([0, -50, 20, -35, -173, -80, 2, -9, -10, -1], [0, 10, 10, 1], 5) == 0)
    assert(coeff([0, -50, 20, -35, -173, -80, 2, -9, -10, -1], [0, 10, 10, 1], 6) == -1)

main()

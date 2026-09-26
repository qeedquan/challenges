#!/usr/bin/env python3

"""

In this challenge, you are given a polynomial p(x) and a positive integer k.
Your task is to compute the sum of the k-th powers of the roots of p(x) (with multiplicity).
In other words, if  r1,r2,…,rn are the roots of p(x), you need to compute Sk=r^k1+r^k2+…+r^kn.

For example, if p(x) = x^4 - 2*x^3 + 2*x^2 - 2x + 1 and k=2,
then the roots of p(x) are r1=1, r2=1, r3=i, and r4=-i.
Therefore, the sum of the squares of the roots is  S2 = 1^2 + 1^2 + i^2 + (-i)^2 = 1 + 1 − 1 − 1 = 0.

A possible way to compute Sk is using the Newton's identities of symmetric polynomials.
Of course, you are free to use any method you like, as long as it produces the correct output.

Input and Output
You may take the input polynomial  p(x) in any reasonable format.
For example, the polynomial x^4 - 4*x^3 + 5*x^2 - 2x may be represented as:

a list of coefficients, in descending order: [1,-4,5,-2,0];
a list of coefficients, in ascending order:[0,-2,5,-4,1];
a string representation of the polynomial, with a chosen variable, e.g., "x^4-4*x^3+5*x^2-2*x";
a built-in polynomial object, e.g., x^4-4*x^3+5*x^2-2*x in PARI/GP.
You may take the degree (n) or the number of coefficients (n+1) as an additional input.

The degree of the input polynomial is at least 1. In other words, it is not a constant polynomial.

The coefficients are all integers, and the lead coefficient (the coefficient of the highest degree term) is always 1. You may choose to take the list of coefficients without the leading 1, e.g., [-4,5,-2,0] instead of [1,-4,5,-2,0].

The output Sk is theoretically always an integer, but floating point errors are allowed in your output.

This is code-golf, so the shortest code in bytes wins.

Test cases
Here the input polynomials are represented as lists of coefficients in descending order.

[1, 1], 1 -> -1
[1, 1], 2 -> 1
[1, 0, 0], 1 -> 0
[1, 0, 0], 2 -> 0
[1, -2, 2, -2, 1], 1 -> 2
[1, -2, 2, -2, 1], 2 -> 0
[1, -2, 2, -2, 1], 3 -> 2
[1, -2, 2, -2, 1], 4 -> 4
[1, -4, 5, -2, 0], 1 -> 4
[1, -4, 5, -2, 0], 2 -> 6
[1, -4, 5, -2, 0], 3 -> 10
[1, -4, 5, -2, 0], 4 -> 18
[1, -4, 5, -2, 0], 5 -> 34
[1, -4, 5, -2, 0], 6 -> 66
[1, -4, 5, -2, 0], 7 -> 130
[1, 2, 3, 4, 5, 6], 1 -> -2
[1, 2, 3, 4, 5, 6], 2 -> -2
[1, 2, 3, 4, 5, 6], 3 -> -2
[1, 2, 3, 4, 5, 6], 4 -> -2
[1, 2, 3, 4, 5, 6], 5 -> -2
[1, 2, 3, 4, 5, 6], 6 -> 40

"""

import numpy as np

def solve(c, k):
    r = 0
    for p in np.roots(c):
        r += p**k
    return int(abs(r))

def main():
    assert(solve([1, 1], 1 == -1))
    assert(solve([1, 1], 2 == 1))
    assert(solve([1, 0, 0], 1 == 0))
    assert(solve([1, 0, 0], 2 == 0))
    assert(solve([1, -2, 2, -2, 1], 1 == 2))
    assert(solve([1, -2, 2, -2, 1], 2 == 0))
    assert(solve([1, -2, 2, -2, 1], 3 == 2))
    assert(solve([1, -2, 2, -2, 1], 4 == 4))
    assert(solve([1, -4, 5, -2, 0], 1 == 4))
    assert(solve([1, -4, 5, -2, 0], 2 == 6))
    assert(solve([1, -4, 5, -2, 0], 3 == 10))
    assert(solve([1, -4, 5, -2, 0], 4 == 18))
    assert(solve([1, -4, 5, -2, 0], 5 == 34))
    assert(solve([1, -4, 5, -2, 0], 6 == 66))
    assert(solve([1, -4, 5, -2, 0], 7 == 130))
    assert(solve([1, 2, 3, 4, 5, 6], 1 == -2))
    assert(solve([1, 2, 3, 4, 5, 6], 2 == -2))
    assert(solve([1, 2, 3, 4, 5, 6], 3 == -2))
    assert(solve([1, 2, 3, 4, 5, 6], 4 == -2))
    assert(solve([1, 2, 3, 4, 5, 6], 5 == -2))
    assert(solve([1, 2, 3, 4, 5, 6], 6 == 40))

main()

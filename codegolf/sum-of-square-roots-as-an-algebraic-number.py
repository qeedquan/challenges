#!/usr/bin/env python3

"""

An algebraic number is a number that is a root of a non-zero polynomial with integer coefficients. It is well-known that the sum of two algebraic numbers is algebraic. In particular, the sum of a list of square roots of integers is algebraic.

In this challenge, you are given a list of distinct positive integers  a1,a2,…,an.
Let S=Sum[i=1, n] sqrt(a[i]).
Your task is to find a non-zero polynomial p(x) with integer coefficients such that p(S)=0.

For example, if  a=[2,3], then  S=sqrt(2) + sqrt(3), and one possible polynomial is p(x) = x^4 - 10x^2 + 1.

Your output does not need to be the minimal polynomial of the sum.

Your output does not need to be the minimal polynomial of the sum.

Input
A list of distinct positive integers, in any reasonable format. You may assume that the input is sorted in any order of your choice.

Output
You may output the polynomial in any reasonable format. Here are some examples of valid output formats:

A list of coefficients, in any order of your choice, e.g.,  x^4 - 10x^2 + 1 could be represented as [1, 0, -10, 0, 1].
A function that takes a non-negative integer k and returns the coefficient of x^k in p(x).
A built-in polynomial type in your language.
This is code-golf, so the shortest code in bytes in each language wins.

Test cases
The output is not unique, so you may output a different polynomial that is also correct.

Here the polynomials are represented as lists of coefficients in decreasing order.

[5] -> [1, 0, -5]
[2, 3] -> [1, 0, -10, 0, 1]
[1, 2, 3] -> [1, -4, -4, 16, -8]
[2, 3, 5] -> [1, 0, -40, 0, 352, 0, -960, 0, 576]
[1, 2, 4, 7] -> [1, -12, 36, 0, -56]
[1, 3, 5, 7] -> [1, -8, -32, 304, -48, -1984, 640, 3584, 1024]

"""

from sympy import *

def solve(c):
    p = minpoly(sum(map(sqrt, c)))
    return Poly(p).all_coeffs()

def main():
    assert(solve([5]) == [1, 0, -5])
    assert(solve([2, 3]) == [1, 0, -10, 0, 1])
    assert(solve([1, 2, 3]) == [1, -4, -4, 16, -8])
    assert(solve([2, 3, 5]) == [1, 0, -40, 0, 352, 0, -960, 0, 576])
    assert(solve([1, 2, 4, 7]) == [1, -12, 36, 0, -56])
    assert(solve([1, 3, 5, 7]) == [1, -8, -32, 304, -48, -1984, 640, 3584, 1024])

main()

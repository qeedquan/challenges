#!/usr/bin/env python3

"""

We say a polynomial sequence p[n](x) is of binomial type, if for all n≥0 we have

p[n](x + y) = Sum[k=0, n] binomial(n, k) * p[k](x) * p[n-k](y)


Here are some well-known examples of polynomial sequences of binomial type:

The monomials  x[n].
The falling factorials (x)[n]=x(x-1)⋯(x-n+1).
The rising factorials (x)[n]=x(x+1)⋯(x+n−1).
The Abel polynomials  p[n](x)=x(x−na)^(n-1) for some fixed constant a.

Polynomial sequences of binomial type are a fundamental concept in the theory of umbral calculus. Other related concepts include Sheffer sequences and Appell sequences.

In this challenge, you are given a finite sequence of polynomials pn(x), 0≤n≤N, where pn(x) is of degree n.
Your task is to determine whether it is of binomial type.
In other words, you need to check whether the binomial identity holds for all 0≤n≤N.

Input and Output
You may take the input polynomials in any reasonable format. For example, the polynomial  x4−4x3+5x2−2x
  may be represented as:

a list of coefficients, in descending order: [1,-4,5,-2,0];
a list of coefficients, in ascending order:[0,-2,5,-4,1];
a string representation of the polynomial, with a chosen variable, e.g., "x^4-4*x^3+5*x^2-2*x";
a built-in polynomial object, e.g., x^4-4*x^3+5*x^2-2*x in PARI/GP.
The coefficients are all integers.

N is at least 0. So you don't need to handle the case of an empty sequence.

The degree of p[n](x) is exactly n for all 0≤n≤N.
In particular, p[0](x) is a nonzero constant polynomial.

When representing the polynomials as lists of coefficients,
you may assume that the coefficient lists are padded with zeros so that the whole input is a rectangular array,
if that is convenient for your language.
For example, the sequence of polynomials  {1,x,x^2,x^3} could be represented as [[0,0,0,1],[0,0,1,0],[0,1,0,0],[1,0,0,0]]
(in descending order) or [[1,0,0,0],[0,1,0,0],[0,0,1,0],[0,0,0,1]] (in ascending order).
Of course, you may also choose to take the input without padding.

You may take N or N+1 as an additional input.

This is a decision-problem.
You may use your language's convention for truthy and falsy values (swapping is allowed).
You may also use two distinct, fixed values to represent true and false.

This is code-golf, so the shortest code in bytes wins.

Test cases
Here the input polynomials are represented as lists of coefficients in descending order without padding.

[[1]] -> True
[[1],[1,0]] -> True
[[1],[1,0],[1,0,0],[1,0,0,0]] -> True
[[1],[1,0],[1,-1,0],[1,-3,2,0]] -> True
[[1],[1,0],[1,1,0],[1,3,2,0]] -> True
[[1],[1,0],[1,-2,0],[1,-6,9,0]] -> True
[[1],[1,0],[1,-4,0],[1,-12,36,0],[1,-24,192,-512,0]] -> True
[[2]] -> False
[[1],[2,0],[1,0,0]] -> False
[[1],[1,1],[1,0,0]] -> False
[[1],[1,0],[1,0,1]] -> False
[[1],[1,0],[2,0,0]] -> False
[[1],[1,0],[1,0,-1]] -> False
[[1],[1,0],[1,1,0],[1,0,0,0]] -> False

"""

from sympy import binomial, expand, symbols
from sympy.abc import x, y

# Ported from @Tegah D Oweh solution
def check(p, n):
    for m in range(n):
        total = (x - p[m] - x).subs(x, x + y)
        for k in range(m + 1):
            term = p[k] * (p[m - k] + x - x).subs(x, y) * binomial(m, k)
            total += term
        if expand(total) != 0:
            return False
    return True

def main():
    tests = [
        [1],
        [1, x],
        [1, x, x**2, x**3],
        [1, x, x**2 - x, x**3 - 3*x**2 + 2*x],
        [1, x, x**2 + x, x**3 + 3*x**2 + 2*x],
        [1, x, x**2 - 2*x, x**3 - 6 * x**2 + 9*x],
        [1, x, x**2 - 4*x, x**3 - 12*x**2 + 36*x, x**4 - 24*x**3 + 192*x**2 - 512*x],
        [2],
        [1, 2 * x, x**2],
        [1, x + 1, x**2],
        [1, x, x**2 + 1],
        [1, x, 2*x**2],
        [1, x, x**2 - 1],
        [1, x, x**2 + x, x**3],
    ]

    for i in range(len(tests)):
        if i <= 6:
            assert(check(tests[i], len(tests[i])) == True)
        else:
            assert(check(tests[i], len(tests[i])) == False)

main()

#!/usr/bin/env python3

"""

Given the value of n! (n!=1⋅2⋅…⋅(n−1)⋅n), determine the value of n.

Input
The input contains the value of n! (1≤n≤2000).

Output
Output the value of the positive integer n.

Examples

Input #1
5040

Answer #1
7

"""

from scipy.special import gammaln
from scipy.optimize import bisect
from math import log

def inverse_log_gamma(logarg):
    assert(logarg > 0)
    a = 1
    b = 2
    while b < logarg:
        b = b*2
    return bisect(lambda x: gammaln(x) - logarg, a, b)

def inverse_factorial(logarg):
    g = inverse_log_gamma(logarg)
    return round(g) - 1

# https://www.johndcook.com/blog/2024/01/01/inverse-factorial/
def solve(n):
    return inverse_factorial(log(n))

def main():
    assert(solve(120) == 5)
    assert(solve(5040) == 7)

main()

#!/usr/bin/env python3

"""

Given value of n, find the sum

Sum[k=1 to n] 1/k^2

Input
One positive integer n (n≤10^9).

Output
Print the value of the sum with 6 decimal digits.

Examples

Input #1
2

Answer #1
1.250000

Input #11
1234567

Answer #11
1.644933

"""

from scipy.special import polygamma
from math import pi
import numpy as np

"""

https://en.wikipedia.org/wiki/Basel_problem
https://link.springer.com/article/10.1186/1029-242X-2013-75

"""

def solve(n):
    return pi**2/6 - polygamma(1, n + 1)

def solvebf(n):
    r = 0
    for i in range(1, n + 1):
        r += 1/i**2
    return r

def main():
    print(solve(2))
    print(solve(1234567))

    for i in range(10000):
        assert(np.allclose(solve(i), solvebf(i)))

main()

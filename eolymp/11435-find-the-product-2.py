#!/usr/bin/env python3

"""

For the given positive integer n find the product

(1 + 1/1^2) * (1 + 1/2^2) * ... (1 + 1/n^2)

Input
One integer n(n≤1000).

Output
Print the value of the product with 6 decimal digits.

Examples

Input #1
3

Answer #1
2.777778

"""

from scipy.special import gamma
from math import sinh, pi, factorial
import numpy as np

def solve(n):
    r = 1
    for i in range(1, n + 1):
        r *= (1 + 1/i**2)
    return r

# https://math.stackexchange.com/questions/2039393/what-is-the-value-of-prod-n-1-infty-1-frac1n2
def solvecf(n):
    r = sinh(pi)/pi * (gamma(n+1+1j)*gamma(n+1-1j))/factorial(n)**2
    return r.real

def main():
    print(solve(3))
    print(solve(1000))

    for i in range(95):
        assert(np.allclose(solve(i), solvecf(i)))

main()


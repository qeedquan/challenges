#!/usr/bin/env python3

"""

Given a number n, find x such that x! = n, where both x and n are positive integers.
Assume the input n will always be the factorial of a positive integer, so something like n=23 will not be given as input.

Examples: n=1 -> x=1 (0 is not a positive integer), n=24 -> x=4

Shortest code wins.

"""

from scipy.special import lambertw, gamma
from math import factorial
import numpy as np

# http://mathoverflow.net/questions/12828/inverse-gamma-function
def gamma_inverse(x):
    # the positive zero of the digamma function, scipy.special.psi
    k = 1.461632
    assert x >= k, 'gamma(x) is strictly increasing for x >= k, k=%1.2f, x=%1.2f' % (k, x)
    C = np.sqrt(2*np.pi)/np.e - gamma(k)
    L = np.log((x + C) / np.sqrt(2*np.pi))
    return 0.5 + L / lambertw(L/np.e)

def factorial_inverse(n):
    if n < 1:
        return 0
    if n <= 2:
        return n
    r = gamma_inverse(n)
    return int(r.real)

def main():
    for i in range(1, 100):
        assert(i == factorial_inverse(factorial(i)))

main()

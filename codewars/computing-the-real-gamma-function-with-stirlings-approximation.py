#!/usr/bin/env python3

"""

Computing the real Gamma Function with Stirling's Approximation
Related Kata
Computing the complex Gamma function <-- click on the link to attempt the Kata now :D

Related Collection
Complex Analysis

Overview
The Gamma Function Γ(x) is an extension of the factorial function - while the factorial n! is only defined for non-negative integers, the gamma function is defined for all numbers except the non-positive integers. However, the gamma function has its argument shifted down by 1 such that Γ(n) = (n - 1)! for all n where n is a positive integer. One of its many applications is in fractional calculus.

Definitions
The main definition of the gamma function is based on a definite integral with positive infinity as one of its limits. There are also other exact definitions of the gamma function such as "Euler's definition as an infinite product" and the "Weierstrass definition". However, I will not elaborate on these definitions - more information can be easily found on Wikipedia (or by consulting your math professor).

The Problem
It is technically impossible to implement an exact definition of the Gamma Function in a computer/calculator since "there are, relatively speaking, no such simple solutions for factorials; no finite combination of sums, products, powers, exponential functions, or logarithms will suffice to express x!" (source: Wikipedia) so one must always resort to numerically approximating the Gamma function, ideally to a high degree of accuracy. A common, well-known approximation to the Gamma Function is known as Stirling's Approximation which has a simple formula and is usually sufficiently accurate for large values of x; however, since it is an asymptotic approximation, it loses its accuracy for small values of x and doesn't work with negative values of x due to an attempt at squarerooting a negative number (JavaScript Math.sqrt returns NaN for negative inputs).

The Challenge
Stirling's Approximation is implemented in this Kumite as a possible implementation for the Gamma Function; however, you will notice that it fails most, if not all, of the tests. The challenge, should you accept it, is to properly implement the Gamma Function such that it passes all test cases properly.

function gamma(x) {
  // Stirling's Approximation is simple and efficient (just a single calculation)
  // but will it work?
  x -= 1; // Shift argument down by 1
  return Math.sqrt(2 * Math.PI * x) * Math.pow(x / Math.E, x); // Compute Stirling's Formula
}

"""

import numpy as np
from math import *

"""

https://en.wikipedia.org/wiki/Spouge%27s_approximation

Use approximation to calculate
Gamma(x + 1)

Use identity Gamma(x + 1) = x * Gamma(x)

Gamma(x) = x / Gamma(x + 1)

For integer values Gamma(x) = Factorial(x)

"""

def mygamma(z):
    if type(z) is int:
        return factorial(z)

    a = 50
    s = sqrt(2*pi)
    for k in range(1, a):
        c = (-1)**(k - 1)/factorial(k - 1) * (-k + a)**(k - 0.5) * exp(-k + a)
        s += c / (z + k)
    r = (z + a)**(z + 0.5) * exp(-z - a) * s
    return r / z

def main():
    for z in range(52):
        assert(mygamma(z) == factorial(z))
    
    assert(np.allclose(mygamma(1/2), sqrt(pi)))
    assert(np.allclose(mygamma(3/2), 1/2*sqrt(pi)))
    assert(np.allclose(mygamma(5/2), 3/4*sqrt(pi)))
    assert(np.allclose(mygamma(7/2), 15/8*sqrt(pi)))

    assert(np.allclose(mygamma(-1/2), -2*sqrt(pi)))
    assert(np.allclose(mygamma(-3/2), 4/3*sqrt(pi)))
    assert(np.allclose(mygamma(-5/2), -8/15*sqrt(pi)))

main()

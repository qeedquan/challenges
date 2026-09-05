#!/usr/bin/env python3

"""

A polynomial is divisible by a factor (x-n) if f(n)=0 for a function f. Your job: to determine if a polynomial function f(x) is divisible by (x-n).

The input
The input is in the form of (x-n), (Polynomial). Remember, if n is negative, (x-n) will be in the input form of (x+n).
For the polynomial, all exponents will be put in as ^. Coefficients will be written next to the variable x.
An example polynomial could be 2x^2 + x^1. There will be no spaces between anything.
The term x will be inputed as x^1. So what would "normally" look like (x - 1) will be (x^1-1). The coefficients and powers will always be integers. The coefficient one will be implicit if it is just x. I.e., x can be interpreted as 1x

The output
A boolean value. Truthy, or Falsey.

Thanks to @AlexA. For helping me clarify this!

Examples
Input:(x^1-1),(x^1-1)
Output: True

Input: (x^1+2),(2x^2+4x^1+2)
Output: False

Input: (x^1+7),(x^2-49)
Output: True

Rules
This is code-golf, so shortest code in bytes wins

"""

from sympy import *
from sympy.abc import *

def divisible(q, p):
    return rem(p, q) == 0

def main():
    assert(divisible(x**1 - 1, x**1 - 1) == True)
    assert(divisible(x**1 + 2, 2*x**2 + 4*x**1 + 2) == False)
    assert(divisible(x**1 + 7, x**2 - 49) == True)

main()

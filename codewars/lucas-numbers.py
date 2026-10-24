#!/usr/bin/env python3

"""

Lucas numbers are numbers in a sequence defined like this:

L(0) = 2
L(1) = 1
L(n) = L(n-1) + L(n-2)
Your mission is to complete the function that returns the nth term of this sequence.

Note: It should work for negative numbers as well; how you do this is you flip the equation around, so for negative numbers: L(n) = L(n+2) - L(n+1)

Examples
L(-10) = 123
L(-5)  = -11
L(-1)  =  -1
L(0)   =   2
L(1)   =   1
L(5)   =  11
L(10)  = 123

"""

from math import *

# https://oeis.org/A000032
# https://oeis.org/A061084
def lucas(n):
    a = (1 + sqrt(5)) / 2
    b = (1 - sqrt(5)) / 2
    return round(a**n + b**n)

def main():
    assert(lucas(-10) == 123)
    assert(lucas(-5) == -11)
    assert(lucas(-1) == -1)
    assert(lucas(0) == 2)
    assert(lucas(1) == 1)
    assert(lucas(2) == 3)
    assert(lucas(5) == 11)
    assert(lucas(10) == 123)

main()

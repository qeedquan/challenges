#!/usr/bin/env python3

"""

Challenge
So, um, it seems that, while we have plenty of challenges that work with square numbers or numbers of other shapes, we don't have one that simply asks:

Given an integer n (where n>=0) as input return a truthy value if n is a perfect square or a falsey value if not.

Rules
You may take input by any reasonable, convenient means as long as it's permitted by standard I/O rules.
You need not handle inputs greater than what your chosen language can natively handle nor which would lead to floating point inaccuracies.
Output should be one of two consistent truthy/falsey values (e.g., true or false, 1 or 0) - truthy if the input is a perfect square, falsey if it's not.
This is code-golf so lowest byte count wins.

Test Cases
Input:  0
Output: true

Input:  1
Output: true

Input:  64
Output: true

Input:  88
Output: false

Input:  2147483647
Output: false

"""

from math import *

def is_square(n):
    s = int(sqrt(n))
    return s*s == n

def main():
    assert(is_square(0) == True)
    assert(is_square(1) == True)
    assert(is_square(64) == True)
    assert(is_square(88) == False)
    assert(is_square(2147483647) == False)

main()

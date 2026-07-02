#!/usr/bin/env python3

"""

J. E. Maxfield proved following theorem (see DOI: 10.2307/2688966):

If A is any positive integer having m digits, there exists a positive integer N such that the first m digits of N! constitute the integer A.

Challenge
Your challenge is given some A⩾1 find a corresponding N⩾1.

Details
N! represents the factorial N!=1⋅2⋅3⋅…⋅N of N.
The digits of A in our case are understood to be in base 10.
Your submission should work for arbitrary A⩾1 given enough time and memory. Just using e.g. 32-bit types to represent integers is not sufficient.
You don't necessarily need to output the least possible N.

Examples
A            N
1            1
2            2
3            9
4            8
5            7
6            3
7            6
9           96
12           5
16          89
17          69
18          76
19          63
24           4
72           6
841      12745
206591378  314

The least possible N for each A can be found in https://oeis.org/A076219

"""


from math import *
import sys

# https://oeis.org/A076219
def factor(n):
    i = 1
    while True:
        s = str(factorial(i))
        if s.startswith(str(n)):
            return i
        i += 1
    return -1

def main():
    sys.set_int_max_str_digits(0)
    assert(factor(1) == 1)
    assert(factor(2) == 2)
    assert(factor(3) == 9)
    assert(factor(4) == 8)
    assert(factor(5) == 7)
    assert(factor(6) == 3)
    assert(factor(7) == 6)
    assert(factor(9) == 96)
    assert(factor(12) == 5)
    assert(factor(16) == 89)
    assert(factor(17) == 69)
    assert(factor(18) == 76)
    assert(factor(19) == 63)
    assert(factor(24) == 4)
    assert(factor(72) == 6)
    assert(factor(841) == 12745)
    assert(factor(206591378) == 314)

main()

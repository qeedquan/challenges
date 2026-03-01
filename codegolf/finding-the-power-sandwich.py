#!/usr/bin/env python3

"""

Introduction
Finding the closest power to a number is a common enough problem. But what if you need both the next-highest and next-lowest power? In this challenge you must find the closest powers to a given number - the 'power sandwich' if you will, where the given number is the filling and the powers are the bread. Mmm, tasty.

Challenge
Given a power P >0 and a number N >0, output the largest integer x^P that is smaller or equal to N, and the smallest integer y^P that is greater or equal to N.

Input should be taken as a list of two positive (>0) integers, first the power P and then the number N. Output should be a list of two integers, the first being smaller or equal to N, the second being greater or equal to N, and both being a power of P.

If N is a power of P already, the output should be the list [N, N].

This is code-golf, so the shortest code (as measured in bytes) wins.

Example Input and Output
Input:

[2, 17]

Output:

[16, 25]

Explanation: 16 is the biggest square number (power of 2) less than or equal to 17, and 25 is the smallest square number greater or equal to 17.

Test cases
[2, 24] -> [16, 25]
[2, 50] -> [49, 64]
[3, 8] -> [8, 8]
[1, 25] -> [25, 25]
[3, 25] -> [8, 27]
[4, 4097] -> [4096, 6561]
[2, 10081] -> [10000, 10201]
[11, 2814661] -> [177147, 4194304]
[6, 1679616] -> [1000000, 1771561]

"""

from math import *

def powersandwich(p, n):
    y = floor(n**(1/p))
    x = y**p
    if x < n:
        y += 1
    y = y**p
    return (x, y)

def main():
    assert(powersandwich(2, 17) == (16, 25))
    assert(powersandwich(2, 24) == (16, 25))
    assert(powersandwich(2, 50) == (49, 64))
    assert(powersandwich(3, 8) == (8, 8))
    assert(powersandwich(1, 25) == (25, 25))
    assert(powersandwich(3, 25) == (8, 27))
    assert(powersandwich(4, 4097) == (4096, 6561))
    assert(powersandwich(2, 10081) == (10000, 10201))
    assert(powersandwich(11, 2814661) == (177147, 4194304))
    assert(powersandwich(6, 1679616) == (1000000, 1771561))

main()

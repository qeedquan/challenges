#!/usr/bin/env python3

"""

A staircase number is a positive integer x such that its nth digit (one indexed starting with the least significant digit) is equal to x % (n + 1). Thats a bit of a mouthful so lets look at an example. Take 7211311, if we take the modular residues of 7211311 on the range 2-8 we get the following:

7211311 % 2 = 1
7211311 % 3 = 1
7211311 % 4 = 3
7211311 % 5 = 1
7211311 % 6 = 1
7211311 % 7 = 2
7211311 % 8 = 7
These are the digits of 7211311! Thus 7211311 is a staircase number.

Task
Write code that takes when given a positive number as input, will output two distinct values one if the number is a staircase number and the other if it is not.

This is a code-golf competition so your aim should be to minimize the number of bytes in your source code.

Test Cases
Here are the first 13 staircase numbers:

1, 10, 20, 1101, 1121, 11311, 31101, 40210, 340210, 4620020, 5431101, 7211311, 12040210

"""

from math import *

# https://oeis.org/A319599
def staircase(n):
    if n < 1:
        return 0

    t = n
    for i in range(1, int(log10(n)+2)):
        if n%(i+1) != t%10:
            return False
        t //= 10
    return True

def gen(n):
    r = []
    i = 0
    while len(r) < n:
        if staircase(i):
            r.append(i)
        i += 1
    return r

def main():
    tab = [1, 10, 20, 1101, 1121, 11311, 31101, 40210, 340210, 4620020, 5431101, 7211311, 12040210]

    assert(gen(len(tab)) == tab)

main()

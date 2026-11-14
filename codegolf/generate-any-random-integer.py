#!/usr/bin/env python3

"""

Your program/function should

output exactly one integer
output any integer with positive probability
output an integer greater than 1.000.000 or less than -1.000.000 with at least with 50% probability.
Example outputs (all must be possible):

59875669123
12
-42
-4640055890
0
2014
12
24
-7190464664658648640055894646646586486400558904644646646586486400558904646649001

Clarifications:

A trailing line break is permitted.
Leading zeros aren't allowed.
-0 is permitted.
Shortest code wins.

"""

from random import *

"""

Ported from @kennytm solution

It is trivial to check that the while loop in the middle can generate all integers (albeit biased towards zero). "12" is chosen such that there are roughly half of numbers exceeding ±10^6.

"""

def gen():
    s = 0
    while randrange(12):
        s = s*9 + randrange(-8, 9)
    return s

def main():
    print(gen())

main()

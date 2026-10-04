#!/usr/bin/env python3

"""

There are n lamps.
For each lamp, the flashing period (in seconds) is given.
Initially, all the lamps flash simultaneously.
Determine when they will next flash simultaneously.

Input
The first line contains the integer n (2≤n≤10), the number of lamps.

The second line contains n positive integers — the flashing periods of the lamps, each not exceeding 100.

Output
Print the time in seconds when all the lamps will next flash simultaneously.

Examples
Input #1
3
3 6 8

Answer #1
24

"""

from math import lcm

def solve(a):
    if len(a) == 0:
        return 0

    r = 1
    for x in a:
        r = lcm(r, x)
    return r

def main():
    assert(solve([3, 6, 8]) == 24)

main()

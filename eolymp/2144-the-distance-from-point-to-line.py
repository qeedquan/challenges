#!/usr/bin/env python3

"""

Find the distance from the point O to the line ax+by+c=0.

Input
Five integers are given: the coordinates of the point O and the coefficients a, b, c of the equation of the line.
All numbers do not exceed 10000 by absolute value.

Output
Print one number — the distance from the point O to the line with an accuracy of at least 10^-6.

Examples
Input #1
1 1 1 1 -1

Answer #1
0.70710678

"""

from math import hypot

def solve(x, y, a, b, c):
    return abs(a*x + b*y + c) / hypot(a, b)

def main():
    print(solve(1, 1, 1, 1, -1))

main()

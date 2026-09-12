#!/usr/bin/env python3

"""

There are two points in the plane. We can draw two segments from the origin to each of these points. Calculate the angle between these two segments.

The angle should be given in radians and must be less than 3.1415926…. Be careful, it is an angle, not an angel.

Input
The first line contains a single integer T, indicating the number of test cases.
Each test case consists of four integers Xa, Ya, Xb, Yb (−10000≤Xa,Xb,Ya,Yb≤10000), indicating the coordinates of the two points.
You may assume neither of the points coincides with the origin.

Output
For each test case, output the angle rounded to three fractional digits.

Examples

Input #1
2
0 1 1 0
1 2 2 1

Answer #1
1.571
0.644

"""

from math import *

def dot(p, q):
    return p[0]*q[0] + p[1]*q[1]

def length(p):
    return hypot(p[0], p[1])

def angle(p, q):
    return acos(dot(p, q) / (length(p) * length(q)))

def main():
    print(angle([0, 1], [1, 0]))
    print(angle([1, 2], [2, 1]))

main()

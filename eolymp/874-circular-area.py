#!/usr/bin/env python3

"""

Two circles are given by the coordinates of their centers in a rectangular Cartesian coordinate system and their radii. Find the area of their intersection.

Input
In the first row there are 6 real numbers by a space - the coordinates of the centers and radii of two circles: x1, y1, r1, x2, y2, r2.
All numbers are real and do not exceed 1000 in absolute value.

Output
Print a single real number with 2 digits after the decimal point - the area of intersection of circles.

Examples

Input #1
20.0 30.0 15.0 40.0 30.0 30.0

Answer #1
608.37

"""

from math import *

# https://mathworld.wolfram.com/Circle-CircleIntersection.html
# https://mathworld.wolfram.com/images/equations/Circle-CircleIntersection/Inline41.svg
def solve(x1, y1, r1, x2, y2, r2):
    d = hypot(x2-x1, y2-y1)
    r = r1
    R = r2
    A1 = r * r * acos((d*d+r*r-R*R)/(2*d*r))
    A2 = R * R * acos((d*d+R*R-r*r)/(2*d*R))
    A3 = sqrt((-d+r+R)*(d+r-R)*(d-r+R)*(d+r+R)) / 2
    return A1 + A2 - A3

def main():
    print("%.2f" % solve(20.0, 30.0, 15.0, 40.0, 30.0, 30.0))

main()


#!/usr/bin/env python3

"""

Given a segment in space (x1,y1,z1)—(x2,y2,z2) and a point (x,y,z). Find the distance from the point to the segment.

Input
You are given integers x1,y1,z1,x2,y2,z2,x,y,z. The absolute value of each coordinate does not exceed 1000.

Output
Print the required distance with at least 6 digits after the decimal point.

Examples

Input #1
0 0 0
1 1 1
0 0 1

Answer #1
0.8164965809

"""

from math import sqrt

"""

https://en.wikipedia.org/wiki/Distance_from_a_point_to_a_line
https://brilliant.org/wiki/3d-coordinate-geometry-distance/
https://proofwiki.org/wiki/Distance_Formula/3_Dimensions
https://math.stackexchange.com/questions/2012631/distance-from-point-to-line-in-3d

"""

def solve(x1, y1, z1, x2, y2, z2, x, y, z):
    a = (x - x1)*(x2 - x1) + (y - y1)*(y2 - y1) + (z - z1)*(z2 - z1)
    b = (x2 - x1)**2 + (y2 - y1)**2 + (z2 - z1)**2
    t = max(0, min(1, a/b))
    d1 = x - (x1 + t*(x2 - x1))
    d2 = y - (y1 + t*(y2 - y1))
    d3 = z - (z1 + t*(z2 - z1))
    return sqrt(d1**2 + d2**2 + d3**2)

def main():
    print(solve(0, 0, 0, 1, 1, 1, 0, 0, 1))

main()

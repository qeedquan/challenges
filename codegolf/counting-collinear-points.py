#!/usr/bin/env python3

"""

Given two points (x1,y1) and (x2,y2) with integer coordinates, calculate the number of integer points (excluding the given points) that lie on the straight line segment joining these two points.
Use any maths formula you like, such as

https://math.stackexchange.com/questions/301890/how-many-points-between-two-points
gcd(|x2-x1|,|y2-y1|)-1

Input

Four integer coordinates of the two points: x1,y1,x2,y2.

Output

Number of integer points between the two given points.

Test Cases

https://i.stack.imgur.com/HMNZ7.png

Integer Coordinates	In-between Points
(5,10),(10,5)	4
(-8,5),(0,5)	7
(-3,-3),(2,2)	4

C (gcc), 109 bytes
g(a,b){return b?g(b,a%b):a;}main(x,y,a,b){scanf("%d%d%d%d",&x,&y,&a,&

"""

from math import *

def points(x1, y1, x2, y2):
    return gcd(abs(x2 - x1), abs(y2 - y1)) - 1

def main():
    assert(points(5, 10, 10, 5) == 4)
    assert(points(-8, 5, 0, 5) == 7)
    assert(points(-3, -3, 2, 2) == 4)

main()

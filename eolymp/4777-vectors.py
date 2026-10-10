#!/usr/bin/env python3

"""

Given two non-zero vectors, your task is to compute the following:

The lengths of the first and second vectors (two separate numbers).

The vector resulting from the addition of the two given vectors.

The scalar (dot) product and the vector (cross) product of the given vectors.

The area of the triangle formed by these vectors.

Input
The input consists of two lines. The first line contains four integers representing the coordinates of the start and end points of the first vector.
The second line contains four integers representing the coordinates of the start and end points of the second vector.
Each integer does not exceed 10000 in absolute value.

Output
For each task item, output the result on a new line, ensuring a precision of at least 10^−6.

Examples
Input #1
5 1 2 6
1 1 7 8

Answer #1
5.830951895 9.219544457
3.000000000 12.000000000
17.000000000 -51.000000000
25.500000000

"""

from math import sqrt

class Vec2:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __add__(self, other):
        return Vec2(self.x + other.x, self.y + other.y)

    def __sub__(self, other):
        return Vec2(self.x - other.x, self.y - other.y)

    def __str__(self):
        return ("%f %f" % (self.x, self.y))

def norm(a):
    return sqrt(dot(a, a))

def dot(a, b):
    return a.x*b.x + a.y*b.y

def wedge(a, b):
    return (a.x * b.y) - (a.y * b.x)

def area(a, b):
    return 0.5 * abs(wedge(a, b))

def solve(p1, p2, p3, p4):
    a = p2 - p1
    b = p4 - p3
    print(norm(a), norm(b))
    print(a + b)
    print(dot(a, b), wedge(a, b))
    print(area(a, b))

def main():
    solve(Vec2(5, 1), Vec2(2, 6), Vec2(1, 1), Vec2(7, 8))

main()

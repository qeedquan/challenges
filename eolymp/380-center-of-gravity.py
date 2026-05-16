#!/usr/bin/env python3

"""

Given the coordinates of the vertices of a simple polygon, find the coordinates of its center of gravity (centroid).
The sides of the polygon only connect consecutive vertices (including the first and last), and do not intersect each other.
The area of the polygon is nonzero.

Input
The first line contains the number of vertices n (3≤n≤10^5).
Each of the following n lines contains a pair of integers — the coordinates of a point, each with absolute value not exceeding 20000.
If you connect the points in the given order, joining the first and last points as well, you obtain the polygon.

Output
Print two numbers, the coordinates of the centroid, each rounded to two digits after the decimal point.

Examples

Input #1
4
5 0
0 5
-5 0
0 -5

Answer #1
0.00 0.00

Input #2
4
1 1
11 1
11 11
1 11

Answer #2
6.00 6.00

"""

def centroid(p):
    n = len(p)
    x = 0
    y = 0
    a = 0
    for i in range(n):
        j = (i + 1) % n
        d = (p[i][0] * p[j][1]) - (p[j][0] * p[i][1])
        x += (p[i][0] + p[j][0]) * d
        y += (p[i][1] + p[j][1]) * d
        a += d
    a *= 0.5
    x /= 6*a
    y /= 6*a
    return x, y

def main():
    print(centroid([[5, 0], [0, 5], [-5, 0], [0, -5]]))
    print(centroid([[1, 1], [11, 1], [11, 11], [1, 11]]))

main()


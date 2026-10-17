#!/usr/bin/env python3

"""

Suppose you are given several distinct points on a plane, each specified by integer x and y coordinates.
You want to determine the maximum number of points that lie exactly on the same straight line.

Input
The first line contains the number of points n (3≤n≤200).
Each of the next n lines contains the coordinates x and y (−2000≤x,y≤2000), separated by a space.

Output
Print the maximum number of points that lie on a single straight line.

Examples

Input #1
6
7 122
8 139
9 156
10 173
11 190
-100 1

Answer #1
5

"""

from sympy import Matrix

def collinear(x1, y1, x2, y2, x3, y3):
    return Matrix([[x1, y1, 1], [x2, y2, 1], [x3, y3, 1]]).det() == 0

def solve(p):
    n = len(p)
    if n < 2:
        return 0

    r = 2
    for i in range(n):
        for j in range(i + 1, n):
            c = 2
            for k in range(j + 1, n):
                if collinear(p[i][0], p[i][1], p[j][0], p[j][1], p[k][0], p[k][1]):
                    c += 1
            r = max(r, c)
    return r

def main():
    assert(solve([[7, 122], [8, 139], [9, 156], [10, 173], [11, 190], [-100, 1]]) == 5)

main()


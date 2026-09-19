#!/usr/bin/env python3

"""

Given an array of points on the X-Y plane points where points[i] = [xi, yi], return the area of the largest triangle that can be formed by any three different points.
Answers within 10^-5 of the actual answer will be accepted.

Example 1:
Input: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
Output: 2.00000
Explanation: The five points are shown in the above figure. The red triangle is the largest.

Example 2:

Input: points = [[1,0],[0,0],[0,1]]
Output: 0.50000

Constraints:

    3 <= points.length <= 50
    -50 <= xi, yi <= 50
    All the given points are unique.

"""

def area(x1, y1, x2, y2, x3, y3):
    return abs(0.5*(x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2)))

def largest_triangle_area(p):
    r = 0
    n = len(p)
    for i in range(0, n):
        for j in range(0, n):
            for k in range(0, n):
                if i != j and j != k and i != k:
                    r = max(r, area(p[i][0], p[i][1], p[j][0], p[j][1], p[k][0], p[k][1]))
    return r

def test(p, r):
    v = largest_triangle_area(p)
    print(v)
    assert(abs(v-r) < 1e-5)

def main():
    test([[0, 0], [0, 1], [1, 0], [0, 2], [2, 0]], 2)
    test([[1, 0], [0, 0], [0, 1]], 0.5)

main()

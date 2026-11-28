#!/usr/usr/bin/env python3

"""

You are given the cartesian coordinates of a set of points in a 2D plane. When traversed sequentially, these points form a Polygon, P, which is not self-intersecting in nature. Can you compute the area of polygon P?

Input Format

The first line contains an integer, N, denoting the number of points.
The N subsequent lines each contain 2 space-separated integers denoting the respective x and y coordinates of a point.

Constraints
No 2 points are coincident, and polygon P is obtained by traversing the points in a counter-clockwise direction.
4 <= N <= 1000
0 <= x, y <= 1000

Output Format

For each test case, print the area of P (correct to a scale of one decimal place).

Note: Do not add any leading/trailing spaces or units; it is assumed that your result is in square units.

Sample Input
4
0 0
0 1
1 1
1 0

Sample Output
1

Explanation

The given polygon is a square, and each of its sides are 1 unit in length.
area(P) = length * width = 1*1 = 1, so we print 1 on a new line.

"""

def wedge(p, q):
    return p[0]*q[1] - p[1]*q[0]

def shoelace(p):
    n = len(p)
    if n < 3:
        return 0
    
    s = 0
    for i in range(n):
        s += wedge(p[i], p[(i + 1) % n])
    return s / 2

def area(p):
    return abs(shoelace(p))

def main():
    assert(area([[0, 0], [0, 1], [1, 1], [1, 0]]) == 1)
    assert(area([[4, 4], [0, 1], [-2, 5], [-6, 0], [-1, -4], [5, -2], [4, 4]]) == 55)
    assert(area([[2, 1], [5, 0], [6, 4], [4, 2], [1, 3]]) == 8)
    assert(area([[1, 1], [0, 1], [1, 0], [1, 1]]) == 0.5)

main()

#!/usr/bin/env python3

"""

Write a program to find a circle that covers a given set of points with the minimal possible area. Each test case contains at most 100 points.

Input
The input consists of several test cases. Each test case begins with an integer N, the number of points. The next N lines each contain two numbers representing the x and y coordinates of a point, separated by a space. The end of input is marked by a line containing a single 0.

Output
For each test case, output one line with the x and y coordinates of the center and the radius of the minimal covering circle, separated by spaces. Print all values with exactly 2 digits after the decimal point.

Examples
Input #1
2
0.0 0.0
3 0
5
0 0
0 1
1 0
1 1
2 2
0
Answer #1
1.50 0.00 1.50
1.00 1.00 1.41

"""

import math, random

"""

https://www.nayuki.io/page/smallest-enclosing-circle
https://en.wikipedia.org/wiki/Smallest-circle_problem
https://www.cise.ufl.edu/~sitharam/COURSES/CG/kreveldnbhd.pdf

The code implements a variant of Emo Welzl’s algorithm.
With randomization, it runs in expected Θ(n) (linear) time, unlike the brute-force Θ(n^4) algorithm.

"""

def is_in_circle(c, p):
    eps = 1 + 1e-14
    return c is not None and math.hypot(p[0] - c[0], p[1] - c[1]) <= c[2] * eps

def cross_product(x0, y0, x1, y1, x2, y2):
    return (x1 - x0) * (y2 - y0) - (y1 - y0) * (x2 - x0)

def make_diameter(a, b):
    cx = (a[0] + b[0]) / 2
    cy = (a[1] + b[1]) / 2
    r0 = math.hypot(cx - a[0], cy - a[1])
    r1 = math.hypot(cx - b[0], cy - b[1])
    return (cx, cy, max(r0, r1))

def make_circumcircle(a, b, c):
    ox = (min(a[0], b[0], c[0]) + max(a[0], b[0], c[0])) / 2
    oy = (min(a[1], b[1], c[1]) + max(a[1], b[1], c[1])) / 2
    ax = a[0] - ox;  ay = a[1] - oy
    bx = b[0] - ox;  by = b[1] - oy
    cx = c[0] - ox;  cy = c[1] - oy
    d = (ax * (by - cy) + bx * (cy - ay) + cx * (ay - by)) * 2.0
    if d == 0.0:
        return None
    x = ox + ((ax*ax + ay*ay) * (by - cy) + (bx*bx + by*by) * (cy - ay) + (cx*cx + cy*cy) * (ay - by)) / d
    y = oy + ((ax*ax + ay*ay) * (cx - bx) + (bx*bx + by*by) * (ax - cx) + (cx*cx + cy*cy) * (bx - ax)) / d
    ra = math.hypot(x - a[0], y - a[1])
    rb = math.hypot(x - b[0], y - b[1])
    rc = math.hypot(x - c[0], y - c[1])
    return (x, y, max(ra, rb, rc))

def make_circle_one_point(points, p):
    c = (p[0], p[1], 0.0)
    for (i, q) in enumerate(points):
        if not is_in_circle(c, q):
            if c[2] == 0.0:
                c = make_diameter(p, q)
            else:
                c = make_circle_two_points(points[ : i + 1], p, q)
    return c

def make_circle_two_points(points, p, q):
    circ = make_diameter(p, q)
    left = None
    right = None
    px, py = p
    qx, qy = q
    
    for r in points:
        if is_in_circle(circ, r):
            continue
        
        cross = cross_product(px, py, qx, qy, r[0], r[1])
        c = make_circumcircle(p, q, r)
        if c is None:
            continue
        elif cross > 0.0 and (left is None or cross_product(px, py, qx, qy, c[0], c[1]) > cross_product(px, py, qx, qy, left[0], left[1])):
            left = c
        elif cross < 0.0 and (right is None or cross_product(px, py, qx, qy, c[0], c[1]) < cross_product(px, py, qx, qy, right[0], right[1])):
            right = c
    
    if left is None and right is None:
        return circ
    elif left is None and right is not None:
        return right
    elif left is not None and right is None:
        return left
    elif left is not None and right is not None:
        return left if (left[2] <= right[2]) else right
    else:
        raise AssertionError("Unreachable")

def make_circle(points):
    shuffled = [(float(x), float(y)) for (x, y) in points]
    random.shuffle(shuffled)

    c = None
    for (i, p) in enumerate(shuffled):
        if c is None or not is_in_circle(c, p):
            c = make_circle_one_point(shuffled[:i+1], p)
    return c

def solve(points):
    return make_circle(points)

def main():
    print(solve([(0, 0), (3, 0)]))
    print(solve([(0, 0), (0, 1), (1, 0), (1, 1), (2, 2)]))

main()

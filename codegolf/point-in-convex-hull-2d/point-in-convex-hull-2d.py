#!/usr/bin/env python3

"""

Background
The convex hull of a finite number of points is the smallest convex polygon that contains all of the points, either as vertices or on the interior. For more information, see this question on PGM which defines it very well.

Input
N+1 2-D coordinates (N >= 3) passed through STDIN (with other usual golf inputs allowed too) in the following format (the number of decimals can vary but you can assume it remains "reasonable" and each number can be represented as a float):

0.00;0.00000
1;0.00
0.000;1.0000
-1.00;1.000000

Output
A truthy value printed to STDOUT (or equivalent) if the first point in the list ((0.00;0.00000) in the example above) is in the convex hull of the other N points, and a falsy value otherwise.

This is code-golf, so the shortest solution in bytes wins.

Border cases: you can return any value (but don't crash) if the point lies on the border of the convex hull (i.e. on a side or on a vertex on the outer frontier of the hull), since it is a zero probability event (under any reasonable probability).

Forbidden: anything (language, operator, data structure, built-in or package) that exists only to solve geometric problems (e.g. Mathematica's ConvexHull). General purpose mathematical tools (vectors, matrices, complex numbers etc.) are allowed.

Tests
Should return TRUE: spiralTest1-TRUE, squareTest1-TRUE
Should return FALSE: spiralTest2-FALSE, squareTest2-FALSE

"""

import numpy as np
import cv2

def readpoints(name):
    p = []
    f = open(name)
    for l in f:
        t = l.split(";")
        p.append([float(t[0]), float(t[1])])
    return np.array(p, dtype=np.float32)

def inside(p):
    if len(p) < 2:
        return False
    h = cv2.convexHull(p[1:])
    return cv2.pointPolygonTest(h, p[0], False) >= 0

def test(name, result):
    p = readpoints(name)
    assert(inside(p) == result)

def main():
    test("sample-FALSE", False)
    test("spiralTest1-TRUE", True)
    test("spiralTest2-FALSE", False)
    test("squareTest1-TRUE", True)
    test("squareTest2-FALSE", False)

main()

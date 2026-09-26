#!/usr/bin/env python3

"""

Write a program to determine if the input polygon is convex. The polygon is specified with one line containing N, the number of vertices, then N lines containing the x and y coordinates of each vertex. The vertices will be listed clockwise starting from an arbitrary vertex.

example 1
input
4
0 0
0 1
1 1
1 0
output
convex

example 2
input
4
0 0
2 1
1 0
2 -1
output
concave

example 3
input
8
0 0
0 1
0 2
1 2
2 2
2 1
2 0
1 0
output
convex

x and y are integers, N<1000, and |x|,|y|<1000. You may assume that the input polygon is simple (none of the edges cross, only 2 edges touch each vertex). Shortest program wins.

"""

import numpy as np
import cv2
import sys

def dim(a):
    x0, x1 = sys.maxsize, 0
    y0, y1 = sys.maxsize, 0
    for v in a:
        x0 = min(x0, v[0])
        x1 = max(x1, v[0])
        y0 = min(y0, v[1])
        y1 = max(y1, v[1])
    return x0, y0, x1, y1

def image(a):
    x0, y0, x1, y1 = dim(a)
    w = x1 - x0 + 1
    h = y1 - y0 + 1
    p = np.zeros((w, h, 1), dtype=np.uint8)
    for v in a:
        xi = v[0] - x0
        yi = v[1] - y0
        p[xi, yi] = 255
    return p

def shape(a):
    p = image(a)
    c, _ = cv2.findContours(p, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
    if cv2.isContourConvex(c[0]):
        return "convex"
    return "concave"

def main():
    assert(shape([[0, 0], [0, 1], [1, 1], [1, 0]]) == "convex")
    assert(shape([[0, 0], [2, 1], [1, 0], [2, -1]]) == "concave")
    assert(shape([[0, 0], [0, 1], [0, 2], [1, 2], [2, 2], [2, 1], [2, 0], [1, 0]]) == "convex")

main()

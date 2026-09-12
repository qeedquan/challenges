#!/usr/bin/env python3

from scipy.cluster.hierarchy import DisjointSet
from math import *

def dist(p1, p2):
    dx = p1[0] - p2[0]
    dy = p1[1] - p2[1]
    return hypot(dx, dy)

def solve(p, d):
    uf = DisjointSet()
    n = len(p)
    for i in range(n):
        uf.add(i)

    for i in range(n):
        for j in range(i + 1, n):
            if dist(p[i], p[j]) < d:
                uf.merge(i, j)
    return len(uf.subsets())

def main():
    assert(solve([[1.0, 0.1], [2.0, 0.0], [5.0, 0.2], [6.0, 0.4], [3.0, -0.1]], 1.5) == 2)
    assert(solve([[121.12, 254.06], [645.04, 301.85], [912.49, 568.96]], 4.0) == 3)

main()

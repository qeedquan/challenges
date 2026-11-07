#!/usr/bin/env python3

from scipy.cluster.hierarchy import DisjointSet

def solve(n, b):
    uf = DisjointSet()
    for i in range(1, n + 1):
        uf.add(i)
    for u, v in b:
        uf.merge(u, v)
    return len(uf.subsets())

def main():
    assert(solve(10, [[1, 2], [1, 3], [1, 4], [1, 5], [1, 6], [1, 7], [1, 8], [1, 9], [1, 10], [10, 4]]) == 1)
    assert(solve(10, [[2, 3], [4, 5], [4, 8], [5, 8]]) == 7)

main()

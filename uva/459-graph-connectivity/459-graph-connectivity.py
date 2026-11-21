#!/usr/bin/env python3

from scipy.cluster.hierarchy import DisjointSet

def id(letter):
    return ord(letter) - ord('A')

def solve(largest, edges):
    uf = DisjointSet()
    for i in range(id(largest) + 1):
        uf.add(i)

    for u, v in edges:
        uf.merge(id(u), id(v))
    return len(uf.subsets())

def main():
    assert(solve('E', ['AB', 'CE', 'DB', 'EC']) == 2)

main()


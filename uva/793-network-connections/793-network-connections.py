#!/usr/bin/env python3

from scipy.cluster.hierarchy import DisjointSet

def solve(computers, queries):
    uf = DisjointSet()
    for i in range(computers):
        uf.add(i + 1)

    yes = no = 0
    for op, c0, c1 in queries:
        if op == 'c':
            uf.merge(c0, c1)
        elif op == 'q':
            if uf.connected(c0, c1):
                yes += 1
            else:
                no += 1
    return (yes, no)

def main():
    assert(solve(10, [['c', 1, 5], ['c', 2, 7], ['q', 7, 1], ['c', 3, 9], ['q', 9, 6], ['c', 2, 5], ['q', 7, 5]]) == (1, 2))
    assert(solve(1, [['q', 1, 1], ['c', 1, 1], ['q', 1, 1]]) == (2, 0))

main()

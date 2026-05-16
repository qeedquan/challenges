#!/usr/bin/env python3

from scipy.cluster.hierarchy import DisjointSet

def solve(owes, friends):
    uf = DisjointSet()
    for i in range(len(owes)):
        uf.add(i)
    
    for u, v in friends:
        uf.merge(u, v)

    amount = {}
    for i in range(len(owes)):
        j = min(uf.subset(i))
        if j not in amount:
            amount[j] = owes[i]
        else:
            amount[j] += owes[i]

    for i in amount:
        if amount[i] != 0:
            return "IMPOSSIBLE"
    return "POSSIBLE"

def main():
    assert(solve([100, -75, -25, -42, 42], [[0, 1], [1, 2], [3, 4]]) == "POSSIBLE")
    assert(solve([15, 20, -10, -25], [[0, 2], [1, 3]]) == "IMPOSSIBLE")

main()

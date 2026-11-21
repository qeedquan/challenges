#!/usr/bin/env python3

"""

Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]

"""

from itertools import combinations

def gen(n, k):
    r = range(1, n + 1)
    return list(combinations(list(r), k))

def main():
    print(gen(4, 2))

main()

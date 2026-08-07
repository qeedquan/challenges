#!/usr/bin/env python3

"""

Given an integer n, return the number of structurally unique BST's (binary search trees) which has exactly n nodes of unique values from 1 to n.

Example 1:

Input: n = 3
Output: 5
Example 2:

Input: n = 1
Output: 1

Constraints:

1 <= n <= 19

"""

from math import *

def catalan(n):
    return comb(2*n, n) // (n+1)
 
def numtreesdp(n):
    if n < 2:
        return 1
    p = (n+1)*[0]
    p[0] = 1
    p[1] = 1
    for i in range(2, n+1):
        for j in range(1, i+1):
            p[i] += p[j-1]*p[i-j]
    return p[n]

# https://oeis.org/A000108
# https://aaronice.gitbook.io/lintcode/dynamic_programming/unique-binary-search-trees 
def numtrees(n):
    return catalan(n)

def main():
    assert(numtrees(3) == 5)
    assert(numtrees(1) == 1)
    for i in range(32):
        assert(numtrees(i) == numtreesdp(i))

main()

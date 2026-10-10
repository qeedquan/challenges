#!/usr/bin/env python3

"""

This challenge is very simple. You are given as input a square matrix, represented in any sane way, and you have to output the dot product of the diagonals of the matrix.

The diagonals in specific are the diagonal running from top-left to bottom-right and from top-right to bottom-left.

Test Cases
[[-1, 1], [-2, 1]]  ->  -3
[[824, -65], [-814, -741]]  ->  549614
[[-1, -8, 4], [4, 0, -5], [-3, 5, 2]]  ->  -10
[[0, -1, 0], [1, 0, 2], [1, 0, 1]]  ->  1

"""

def diagdot(m):
    n = len(m)
    r = 0
    for i in range(n):
        r += m[i][i]*m[i][n-i-1]
    return r

def main():
    assert(diagdot([[-1, 1], [-2, 1]]) == -3)
    assert(diagdot([[824, -65], [-814, -741]]) == 549614)
    assert(diagdot([[-1, -8, 4], [4, 0, -5], [-3, 5, 2]]) == -10)
    assert(diagdot([[0, -1, 0], [1, 0, 2], [1, 0, 1]]) == 1)

main()

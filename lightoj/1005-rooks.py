#!/usr/bin/env python3

"""

A rook is a piece used in the game of chess which is played on a board of square grids. A rook can only move vertically or horizontally from its current position and two rooks attack each other if one is on the path of the other.

In the following figure, the dark squares represent the reachable locations for rook R1 from its current position. The figure also shows that the rook R1 and R2 are in attacking positions where R1 and R3 are not. R2 and R3 are also in non-attacking positions.

https://static.lightoj.com/images/problem-1005/rooks-1629705220712.png?style=centerme,haveborder,smallme


Now, given two numbers n and k, your job is to determine the number of ways one can put k rooks on an n x n chessboard so that no two of them are in attacking positions.

Input
Input starts with an integer T (≤ 350), denoting the number of test cases.

Each case contains two integers n (1 ≤ n ≤ 30) and k (0 ≤ k ≤ n^2).

Output
For each case, print the case number and total number of ways one can put the given number of rooks on a chessboard of the given size so that no two of them are in attacking positions. You may safely assume that this number will be less than 1017.

Sample
Input	Output
8
1 1
2 1
3 1
4 1
4 2
4 3
4 4
4 5

Case 1: 1
Case 2: 4
Case 3: 9
Case 4: 16
Case 5: 72
Case 6: 96
Case 7: 24
Case 8: 0

"""

from math import *

def solve(n, k):
    return comb(n, k)**2 * factorial(k)

def main():
    assert(solve(1, 1) == 1)
    assert(solve(2, 1) == 4)
    assert(solve(3, 1) == 9)
    assert(solve(4, 1) == 16)
    assert(solve(4, 2) == 72)
    assert(solve(4, 3) == 96)
    assert(solve(4, 4) == 24)
    assert(solve(4, 5) == 0)

main()

#!/usr/bin/env python3

"""

Given a square integer matrix of size N×N (1<N≤1000), your task is to calculate the sum of the elements that are located below the main diagonal of the matrix.

Input
The first line contains the integer N, which is followed by N rows, each consisting of N integers.

Output
Print the sum of the elements below the main diagonal.

Examples

Input #1
4
3 2 3 4
4 3 2 1
2 5 2 1
2 3 4 5

Answer #1
20

"""

def solve(m):
    r = 0
    n = len(m)
    for i in range(1, n):
        for j in range(i):
            r += m[i][j]
    return r

def main():
    assert(solve([[3, 2, 3, 4], [4, 3, 2, 1], [2, 5, 2, 1], [2, 3, 4, 5]]) == 20)

main()

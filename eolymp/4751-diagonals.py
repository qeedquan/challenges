#!/usr/bin/env python3

"""

In the n×n square table, find the sum of the numbers located on the main and secondary diagonals.

Input
The first line contains an integer n (1≤n≤500). The following n×n matrix consists of integers, each with an absolute value not exceeding 10^5.

Output
Print the sum of the numbers on the main and secondary diagonals of the matrix.

Examples
Input #1
4
1 2 3 4
5 6 7 8
3 2 5 4
8 7 9 3

Answer #1
15 21

"""

def solve(m):
    s0 = 0
    s1 = 0
    n = len(m)
    for i in range(n):
        s0 += m[i][i]
        s1 += m[i][n - i - 1] 
    return (s0, s1)

def main():
    assert(solve([[1, 2, 3, 4], [5, 6, 7, 8], [3, 2, 5, 4], [8, 7, 9, 3]]) == (15, 21))

main()


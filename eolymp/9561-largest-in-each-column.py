#!/usr/bin/env python3

"""

You are given a two-dimensional array of size n×m. Find the largest element in each column.

Input
The first line contains two numbers n and m - the number of rows and columns, respectively. Then n lines of m numbers are given - the elements of array.

All numbers do not exceed 100 by absolute value.

Output
Print m numbers in one line - the answer to the problem.

Examples
Input #1
4 5
1 3 2 4 5
4 2 7 6 5
9 2 3 5 1
7 8 1 7 2

Answer #1
9 8 7 7 5

"""

def solve(m):
    if len(m) == 0 or len(m[0]) == 0:
        return []

    r = []
    for x in range(len(m[0])):
        v = float('-inf')
        for y in range(len(m)):
            v = max(v, m[y][x])
        r.append(v)
    return r

def main():
    assert(solve([[1, 3, 2, 4, 5], [4, 2, 7, 6, 5], [9, 2, 3, 5, 1], [7, 8, 1, 7, 2]]) == [9, 8, 7, 7, 5])

main()

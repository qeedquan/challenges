#!/usr/bin/env python3

"""

A two-dimensional array of size n⋅m is given. Find the number of even elements in it.

Input
The first line contains two numbers n and m — the number of rows and the number of columns, respectively. Then n lines are given with m numbers — the elements of the array.

Output
Print one number — the number of even elements in the array.

Examples

Input #1
4 5
1 3 2 4 5
4 2 7 6 5
9 2 3 5 1
7 8 1 7 2

Answer #1
8

"""

def solve(m):
    r = 0
    for i in range(len(m)):
        for j in range(len(m[i])):
            if m[i][j]%2 == 0:
                r += 1
    return r

def main():
    assert(solve([
        [1, 3, 2, 4, 5],
        [4, 2, 7, 6, 5],
        [9, 2, 3, 5, 1],
        [7, 8, 1, 7, 2],
    ]) == 8)

main()

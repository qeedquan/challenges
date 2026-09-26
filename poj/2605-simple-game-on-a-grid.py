#!/usr/bin/env python3

"""

Description

There is an infinite grid and an m*n rectangle of stones on it (1 <= m,n <= 1000). The stones are located in the knots of the grid.

A following game for a single player is being played. One stone can jump over another along a vertical or a horizontal line. A stone which had been overjumped is taken away. The purpose of the game is to minimize number of stones on a grid.

Given a pair of numbers m and n separated with one space in an input file you are to write a program which should determine a minimal number of the stones left on the grid.

Input

Numbers m and n separated by space.

Output

The minimal number of the stones left on the grid.

Sample Input

3 4

Sample Output

2

Source

Ural State University collegiate programming contest 2000

"""

def stones(m, n):
    if n > m:
        m, n = n, m
    if n == 1 or n == 2:
        return (m + 1) // 2
    if n%3 == 0 or m%3 == 0:
        return 2
    return 1

def main():
    assert(stones(3, 4) == 2)

main()

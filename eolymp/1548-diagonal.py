#!/usr/bin/env python3

"""

The number of diagonals in an n-gon is at least N. What is the smallest possible value that n can take?

https://static.e-olymp.com/content/2d/2dd105fff1e3d9d300d46d879801e0b2c15de403.jpg

Input
Contains no more than 1001 lines. Each line contains a positive integer N (N≤10^15) — the minimum number of diagonals.
The last line contains 0 and should not be processed.

Output
For each test case, print its number and the smallest possible value of n — the number of sides of the polygon.

Examples

Input #1
10
100
1000
0

Answer #1
Case 1: 7
Case 2: 16
Case 3: 47

"""

from math import sqrt

def solve(d):
    if d < 0:
        return 0
	
    D = int(sqrt(9 + 8*d))
    n = (3 + D) // 2
    if n*(n-3)//2 == d:
        return n
    return n + 1

def main():
    assert(solve(10) == 7)
    assert(solve(100) == 16)
    assert(solve(1000) == 47)

main()

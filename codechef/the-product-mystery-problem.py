#!/usr/bin/env python3

"""

Input Format
The first line will contain an integer T - number of test cases. Then the test cases follow.
The first and only line of each test case contains two integers B and C.

Output Format
For each test case, output the minimum value of A such that A*B is divisible by C.

Constraints:
1 <= T <= 10^5
1 <= B, C <= 10^9

Sample 1:
Input
2
2 4
8 12

Output
2
3


"""

from math import *

def minproductbf(b, c):
    if c < 1:
        return 0

    a = 1
    while (a*b)%c != 0:
        a += 1
    return a

def minproduct(b, c):
    g = gcd(b, c)
    if g != 0:
        c //= g
    return c

def main():
    assert(minproduct(2, 4) == 2)
    assert(minproduct(8, 12) == 3)

    N = 600
    for b in range(N):
        for c in range(N):
            assert(minproduct(b, c) == minproductbf(b, c))

main()

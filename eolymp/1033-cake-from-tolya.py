#!/usr/bin/env python3

"""

Tolya wants to treat his friends to a cake on his birthday.
It is known that there may be either n or m people at the party (including the birthday person).
What is the minimum number of pieces (not necessarily equal) into which the cake should be cut so that in either case everyone gets an equal share?

Input
Two integers m and n (1≤m,n≤30000).

Output
Print the minimum number of pieces into which the cake should be cut.

Examples

Input #1
2 3

Answer #1
4

"""

from math import gcd

def solve(m, n):
    return m + n - gcd(m, n)

def main():
    assert(solve(2, 3) == 4)

main()

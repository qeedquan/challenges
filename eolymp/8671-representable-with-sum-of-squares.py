#!/usr/bin/env python3

"""

Find all numbers from 1 to n that can be represented as the sum of two squares of different positive integers.

Input
One positive integer n (n≤10000).

Output
Print in one line, in increasing order, all numbers from 1 to n that can be represented as the sum of two squares of different positive integers.

Examples
Input #1
20

Answer #1
5 10 13 17 20

"""

from math import isqrt

# https://oeis.org/A004431
def solve(n):
    s = [i*i for i in range(1, isqrt(n)+2) if i*i < n]
    s2 = set(a+b for i, a in enumerate(s) for b in s[i+1:] if a+b <= n)
    return sorted(s2)

def main():
    assert(solve(20) == [5, 10, 13, 17, 20])

main()

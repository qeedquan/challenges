#!/usr/bin/env python3

"""

A positive integer is magical if it is divisible by either a or b.

Given the three integers n, a, and b, return the nth magical number. Since the answer may be very large, return it modulo 10^9 + 7.

Example 1:

Input: n = 1, a = 2, b = 3
Output: 2
Example 2:

Input: n = 4, a = 2, b = 3
Output: 6


Constraints:

1 <= n <= 10^9
2 <= a, b <= 4 * 10^4

"""

from math import *

def nth(n, a, b):
    if n == 0 or a == 0 or b == 0:
        return 0

    c = lcm(a, b)
    l = min(a, b)
    r = l * n

    while l < r:
        m = (l + r) // 2
        if m//a + m//b - m//c >= n:
            r = m
        else:
            l = m + 1
    return l % 1000000007

def main():
    assert(nth(1, 2, 3) == 2)
    assert(nth(4, 2, 3) == 6)

main()

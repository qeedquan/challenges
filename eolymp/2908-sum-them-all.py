#!/usr/bin/env python3

"""

Find the sum of all the digits in all integers from a to b inclusive.

Input
Each line contains two integers a and b (0≤a≤b≤2×10^9).

Output
For each test case, print on a separate line the sum of all the digits in all integers from a to b inclusive.

Examples

Input #1
0 3
14 53
24660 308357171

Answer #1
6
296
11379854844

"""

from math import *

def triangular(n):
    return n*(n+1)//2

def recurse(n, a):
    if n < 10:
        return triangular(n)

    d = int(log10(n))
    p = 10**d
    m = n // p
    return m*a[d] + triangular(m-1)*p + m*(1 + n%p) + recurse(n%p, a)

# https://www.geeksforgeeks.org/dsa/count-sum-of-digits-in-numbers-from-1-to-n/#expected-approach-by-using-matical-formula-olenn-time-and-olenn-space
# https://oeis.org/A037123
def sumdigs(n):
    if n < 1:
        return 0

    d = max(int(log10(n)), 1)
    a = [0] * (d + 1)
    a[0] = 0
    a[1] = 45
    for i in range(2, d + 1):
        a[i] = a[i-1]*10 + 45*10**(i - 1)
    return recurse(n, a)

def solve(a, b):
    return sumdigs(b) - sumdigs(a - 1)

def main():
    tab = [
        0, 1, 3, 6, 10, 15, 21, 28, 36, 45, 46, 48, 51, 55, 60, 66, 73, 81, 90,
        100, 102, 105, 109, 114, 120, 127, 135, 144, 154, 165, 168, 172, 177,
        183, 190, 198, 207, 217, 228, 240, 244, 249, 255, 262, 270, 279, 289,
        300, 312, 325, 330, 336, 343, 351, 360, 370, 381
    ]

    for i in range(len(tab)):
        assert(sumdigs(i) == tab[i])

    assert(solve(0, 3) == 6)
    assert(solve(14, 53) == 296)
    assert(solve(24660, 308357171) == 11379854844)

main()


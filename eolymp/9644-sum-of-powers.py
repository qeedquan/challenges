#!/usr/bin/env python3

"""

Find the value of the sum (1^n + 2^n + 2*3^n + 3*4^n + 4*5^n + ... + 99*100^n) % m

Input
Two positive integers n and m (n,m≤10^8).

Output
Print the value of the sum modulo m.

Examples
Input #1
12345678 35242346

Answer #1
5447885

"""

def solve(n, m):
    r = 0
    for i in range(1, 101):
        r += pow(i, n, m) * max(i - 1, 1)
        r %= m
    return r

def main():
    assert(solve(12345678, 35242346) == 5447885)

main()

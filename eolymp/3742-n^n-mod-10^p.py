#!/usr/bin/env python3

"""

Given the integers n and p, compute n^n mod 10^p.

Input
You will be provided with two integers n and p (1≤n≤10^9, 1≤p≤100).

Output
Print a single integer representing n^n mod 10^p.

Examples

Input #1
3 1

Answer #1
7

"""

def solve(n, p):
    return pow(n, n, 10**p)

def main():
    assert(solve(3, 1) == 7)

main()

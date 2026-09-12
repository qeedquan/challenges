#!/usr/bin/env python3

"""

Given a natural number n, determine how many powers of two have exactly n digits.

Input
A natural number n (1≤n≤12).

Output
The number of n-digit powers of two.

Examples
Input #1
2

Answer #1
3

"""

def solve(n):
    r = 0
    for i in range(n + 1):
        if len(str(1 << i)) > n:
            break
        r += 1
    return r

def main():
    assert(solve(2) == 3)

main()

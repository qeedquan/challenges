#!/usr/bin/env python3

"""

Some natural number N can be decomposed into prime factors, among which M factors are equal to 2, and K factors are equal to 5.
How many zeros does the natural number N end with?

Input
The only line contains two numbers M and K (0≤M,K≤32000).

Output
Output a single number — the number of trailing zeros.

Examples
Input #1
2 1

Answer #1
1

"""

def solve(m, k):
    return min(m, k)

def solvebf(m, k):
    s = str(2**m * 5**k)
    r = 0
    for c in s[::-1]:
        if c != '0':
            break
        r += 1
    return r

def main():
    assert(solve(2, 1) == 1)

    for m in range(100):
        for k in range(100):
            assert(solve(m, k) == solvebf(m, k))

main()

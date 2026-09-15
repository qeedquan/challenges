#!/usr/bin/env python3

"""

Display the first n numbers of the sequence 1 2 6 24 120 …

Input
A natural number n, where 1 ≤ n ≤ 20.

Output
The sequence numbers, separated by spaces, in a single line.

Examples
Input #1
7

Answer #1
1 2 6 24 120 720 5040

"""

from math import factorial

def solve(n):
    r = []
    for i in range(1, n + 1):
        r.append(factorial(i))
    return r

def main():
    assert(solve(7) == [1, 2, 6, 24, 120, 720, 5040])

main()

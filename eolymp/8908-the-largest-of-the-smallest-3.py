#!/usr/bin/env python3

"""

Given a natural number n (where n>9), identify the largest natural number that has fewer digits than n.

Input
A natural number n (where n>9).

Output
The largest natural number with fewer digits than n.

Examples

Input #1
11

Answer #1
9

"""

def solve(n):
    return int('9' * (len(str(n)) - 1))

def main():
    assert(solve(11) == 9)

main()

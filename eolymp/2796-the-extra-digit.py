#!/usr/bin/env python3

"""

Given a natural number N, find the largest number that can be obtained by removing one digit from N.

Input
A natural number N (10≤N≤10^32).

Output
Output the answer to the problem.

Examples

Input #1
527

Answer #1
57

"""

# https://oeis.org/A340184
def solve(n):
    r = 0
    s = str(abs(n))
    for i in range(len(s)):
        t = s[:i] + s[i+1:]
        if t != "":
            r = max(r, int(t))
    return r

def main():
    tab = [
        0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 2, 3, 4, 5, 6, 7, 8, 9, 2, 2, 2, 3,
        4, 5, 6, 7, 8, 9, 3, 3, 3, 3, 4, 5, 6, 7, 8, 9, 4, 4, 4, 4, 4, 5, 6, 7,
        8, 9, 5, 5, 5, 5, 5, 5, 6, 7, 8, 9, 6, 6, 6, 6, 6, 6, 6, 7, 8, 9, 7, 7,
        7, 7, 7, 7, 7, 7, 8, 9, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9
    ]

    assert(solve(527) == 57)

    for i in range(len(tab)):
        assert(solve(i) == tab[i])

main()

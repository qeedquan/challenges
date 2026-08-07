#!/usr/bin/env python3

"""

Given a positive integer n, print the number of n-digit positive integers.

Input
One positive integer n (n≤10).

Output
Print the number of n-digit positive integers.

Examples
Input #1
1

Answer #1
9

"""

# https://oeis.org/A052268
def solve(n):
    if n < 1:
        return 0
    return 10**n - 10**(n - 1)

def main():
    tab = [
        9, 90, 900, 9000, 90000, 900000, 9000000, 90000000, 900000000, 9000000000,
        90000000000, 900000000000, 9000000000000, 90000000000000, 900000000000000,
        9000000000000000, 90000000000000000, 900000000000000000, 9000000000000000000,
        90000000000000000000
    ]

    assert(solve(1) == 9)

    for i in range(len(tab)):
        assert(solve(i + 1) == tab[i])

main()

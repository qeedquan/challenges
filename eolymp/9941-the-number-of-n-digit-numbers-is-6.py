#!/usr/bin/env python3

"""

Determine and output the count of natural n-digit numbers that fall outside the interval [a,b].

Input
Three natural numbers n, a, and b are provided on a single line, separated by spaces (1≤n≤12, 1≤a,b≤10^12).

Output
Provide the solution to the problem.

Examples

Input #1
2 3 45

Answer #1
54

"""

def solve(n, a, b):
    if a > b:
        a, b = b, a
    return max(10**n - b - 1, 0)

def main():
    assert(solve(2, 3, 45) == 54)
    assert(solve(1, 1, 2) == 7)

main()

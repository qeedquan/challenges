#!/usr/bin/env python3

"""

Given a positive integer n, determine the number of solutions in positive integers to the equation

1/n = 1/x + 1/y

Input
The input contains a single integer n (1≤n≤10^9).

Output
Output the number of solutions in positive integers for the given equation.

Examples
Input #1
2
Answer #1
3

"""

from sympy import divisor_sigma

# https://oeis.org/A048691
def solve(n):
    if n < 1:
        return 0
    return divisor_sigma(n**2, 0)

def main():
    tab = [
        1, 3, 3, 5, 3, 9, 3, 7, 5, 9, 3, 15, 3, 9, 9, 9, 3, 15, 3, 15, 9, 9, 3,
        21, 5, 9, 7, 15, 3, 27, 3, 11, 9, 9, 9, 25, 3, 9, 9, 21, 3, 27, 3, 15,
        15, 9, 3, 27, 5, 15, 9, 15, 3, 21, 9, 21, 9, 9, 3, 45, 3, 9, 15, 13, 9,
        27, 3, 15, 9, 27, 3, 35, 3, 9, 15, 15, 9, 27, 3, 27
    ]

    assert(solve(2) == 3)

    for i in range(len(tab)):
        assert(solve(i + 1) == tab[i])

main()

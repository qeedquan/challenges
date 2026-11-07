#!/usr/bin/env python3

"""

The program should read a natural number N from the console.
If the number N is equal to 10^M, meaning it is a power of 10, then output the value of M.
Otherwise, output No.

Input
A natural number N.

Output
The solution to the problem.

Examples
Input #1
100

Answer #1
2

Input #2
27

Answer #2
No

"""

from math import log10

def solve(n):
    if n < 1:
        return "No"

    m = int(log10(n))
    if 10**m != n:
        return "No"
    return m

def main():
    assert(solve(100) == 2)
    assert(solve(27) == "No")

main()

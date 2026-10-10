#!/usr/bin/env python3

"""

To decompose a natural number into its prime factors.

Write a function that takes a number as input and returns a list of its prime factors in ascending order, including repetitions.

Input
A single natural number greater than 1 and not exceeding 2⋅10^9.

Output
Output the result of the function in the format demonstrated in the example.

Examples

Input #1
12

Answer #1
[2, 2, 3]

"""

from sympy import factorint

def solve(n):
    r = []
    f = factorint(n)
    for p in f:
        for _ in range(f[p]):
            r.append(p)
    return sorted(r)

def main():
    assert(solve(12) == [2, 2, 3])

main()

#!/usr/bin/env python3

"""

The program receives a natural number m as input, which represents a weight in grams.
Your task is to output, on a single line and separated by a space, the equivalent weight in full kilograms and remaining grams.

Input
A natural number m, 1≤m≤10^12.

Output
The solution to the problem.

Examples

Input #1
1234

Answer #1
1 234

"""

def solve(m):
    return (m//1000, m%1000)

def main():
    assert(solve(1234) == (1, 234))

main()

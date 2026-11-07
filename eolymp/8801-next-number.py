#!/usr/bin/env python3

"""

Read one integer and print the next integer.

Input
One integer n, no more than 10^18 by absolute value.

Output
Print the next integer.

Examples
Input #1
10

Answer #1
11

"""

def solve(n):
    return n + 1

def main():
    assert(solve(10) == 11)

main()

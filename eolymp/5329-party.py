#!/usr/bin/env python3

"""

How many ways are there to choose k out of n participants in the summer computer school, each of whom will receive kefir?
Print the answer modulo 9929.

Input
Two integers n and k(0≤k≤n≤500).

Output
Print the number of ways modulo 9929.

Examples
Input #1
6 3

Answer #1
20

"""

from math import comb

def solve(n, k):
    return comb(n, k) % 9929

def main():
    assert(solve(6, 3) == 20)

main()

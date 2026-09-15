#!/usr/bin/env python3

"""

Vasyl loves prime numbers. He wants to find the sum of the first n prime numbers that is divisible by k. Help him with this task.

Input
One integer k (1≤k≤1000).

Output
Print the smallest possible value of n.

Examples
Input #1
7

Answer #1
5

"""

from sympy import nextprime
from itertools import count

# https://oeis.org/A053050
def solve(k):
    if k < 1:
        return 0

    s = 0
    p = 2
    for n in count(0):
        s += p
        n += 1
        if s%k == 0:
            return n
        p = nextprime(p)
    return r

def main():
    tab = [
        1, 1, 10, 5, 2, 57, 5, 11, 20, 3, 8, 97, 49, 5, 57, 11, 4, 113, 23, 9,
        40, 17, 23, 99, 9, 49, 26, 5, 7, 57, 39, 11, 76, 13, 180, 119, 29, 23,
        119, 11, 6, 305, 10, 17, 242, 23, 39, 119, 40, 9, 179, 49, 25, 187, 17,
        115, 70, 7, 30, 103, 151, 39, 40, 171, 131, 175, 38, 37, 52, 209, 19
    ]

    assert(solve(7) == 5)

    for i in range(len(tab)):
        assert(solve(i + 1) == tab[i])

main()

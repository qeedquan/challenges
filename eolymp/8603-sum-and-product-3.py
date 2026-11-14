#!/usr/bin/env python3

"""

Given a three-digit positive integer. Find the sum and the product of its digits.

Input
One three-digit positive integer n (100≤n≤999).

Output
Print in one line the sum and the product of the digits of n.

Examples

Input #1
234

Answer #1
9 24

"""

def solve(n):
    s = 0
    p = 1
    while n > 0:
        m = n % 10
        s += m
        p *= m
        n //= 10
    return (s, p)

def main():
    assert(solve(234) == (9, 24))

main()

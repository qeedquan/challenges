#!/usr/bin/env python3

"""

The program receives a natural number n as input. Your task is to output the count of odd natural numbers that have exactly n digits.

Input
A natural number n.

Output
The count of odd natural numbers with exactly n digits.

Examples

Input #1
1

Answer #1
5

"""

# https://oeis.org/A137233
def solve(n):
    if n < 1:
        return 0
    return (9*10**(n-1) + 1) // 2

def main():
    tab = [
        5, 45, 450, 4500, 45000, 450000, 4500000, 45000000, 450000000, 4500000000,
        45000000000, 450000000000, 4500000000000, 45000000000000, 450000000000000,
        4500000000000000, 45000000000000000, 450000000000000000, 4500000000000000000,
        45000000000000000000, 450000000000000000000
    ]

    assert(solve(1) == 5)

    for i in range(len(tab)):
        assert(solve(i + 1) == tab[i])

main()

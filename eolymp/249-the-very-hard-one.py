#!/usr/bin/env python3

"""

Positive integer A is a divisor of integer B if B can be divided by A without a remainder.
For example, 15 has 4 divisors: 1, 3, 5, 15.
You are required to determine whether the number of divisors of each given integer is even or odd.

Input
The first line contains the integer N (1≤N≤100). The second line contains N integers Xi(1≤Xi≤10^18), separated by spaces.

Output
Output a single line with N numbers separated by spaces. The i-th number should be 0 if the number of divisors of Xi is even, or 1 if it is odd.

Examples
Input #1
2
4 5

Answer #1
1 0

"""

from sympy import divisor_count

def solve(n):
    return divisor_count(n) % 2

def main():
    assert(solve(4) == 1)
    assert(solve(5) == 0)

main()

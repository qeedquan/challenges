#!/usr/bin/env python3

"""

Given an integer n, your task is to determine how many divisors it has, excluding 1 and n itself.

Implement the following function:

function CountDivisors(n: longint): longint; // Pascal

int CountDivisors(int n); // C++

def CountDivisors(n): // Python

This function should return the number of divisors of n.

Input
The function receives a single integer parameter n where 2≤n<2^31.

Output
The function should return a single integer representing the count of divisors of n, excluding 1 and n itself.

Examples

Input #1
2

Answer #1
0

"""

from sympy import divisor_count

def solve(n):
    return divisor_count(n) - 2

def main():
    assert(solve(2) == 0)
    assert(solve(8) == 2)

main()

#!/usr/bin/env python3

"""

As is well known, the Fibonacci numbers are defined as follows:

F(n) = 0                n = 0
       1                n = 1
       F(n-1) + F(n-2)  n > 1

Given two integers a and b, compute the sum:

S = F(a) + F(a + 1) + ... + F(b)

Input
Each line represents a separate test case and contains two integers a and b (0≤a≤b≤10^9).

Output
For each test case, print on a separate line the value of S modulo 10^9+7.

Examples

Input #1
1 1
3 5
10 1000

Answer #1
1
10
625271457

"""

from sympy import fibonacci

# https://math.stackexchange.com/questions/1211909/sum-of-fibonacci-numbers
def fibsum(n):
    return fibonacci(n + 2) - 1

def solve(a, b):
    mod = 1_000_000_007
    return (fibsum(b) - fibsum(a - 1)) % mod

def main():
    assert(solve(1, 1) == 1)
    assert(solve(3, 5) == 10)
    assert(solve(10, 1000) == 625271457)

main()

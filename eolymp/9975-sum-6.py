#!/usr/bin/env python3

"""

Calculate the sum of the first n numbers in the sequence: 1+2+3+5+8+13+21+…

Input
A natural number n, where 1≤n≤89.

Output
A single number representing the sum of the first n numbers in the sequence.

Examples

Input #1
7

Answer #1
53

"""

from sympy import fibonacci

def solvebf(n):
    r = 0
    for i in range(1, n + 1):
        r += fibonacci(i + 1)
    return r

# https://math.stackexchange.com/questions/1211909/sum-of-fibonacci-numbers
def solve(n):
    return fibonacci(n + 3) - 2

def main():
    assert(solve(7) == 53)

    for i in range(50):
        assert(solve(i) == solvebf(i))

main()


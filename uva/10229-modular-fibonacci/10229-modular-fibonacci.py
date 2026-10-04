#!/usr/bin/env python3

from sympy import fibonacci

def solve(n, m):
    return fibonacci(n) % (1<<m)

def main():
    assert(solve(11, 7) == 89)
    assert(solve(11, 6) == 25)

main()


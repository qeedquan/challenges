#!/usr/bin/env python3

from sympy import fibonacci

def solve(n):
    if n < 1:
        return (0, 0)
    
    n += 2
    return (fibonacci(n) - 1, fibonacci(n + 1) - 1)

def main():
    assert(solve(1) == (1, 2))
    assert(solve(3) == (4, 7))

main()


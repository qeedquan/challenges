#!/usr/bin/env python3

"""

Find the value of the function

f(x, y) = 0                                        x <= 0 or y <= 0
          f(x - 1, y - 2) + f(x - 2, y - 1) + F(x) x <= y
          f(x - 2, y - 2) + F(y)                   x > y

where F(n) is the n-th Fibonacci number, defined as follows:

F(0) = 2
F(1) = 3
F(n) = F(n - 1) + F(n - 2)

Input
Three integers x,y,m (0≤x,y≤500,m≤10^9).

Output
Print the value of the function f(x,y) mod m.

Examples

Input #1
11 22 10000

Answer #1
3072

"""

from functools import lru_cache
from sympy import fibonacci

@lru_cache(maxsize=None)
def f(x, y):
    if x <= 0 or y <= 0:
        return 0
    if x <= y:
        return f(x - 1, y - 2) + f(x - 2, y - 1) + fibonacci(x + 3)
    return f(x - 2, y - 2) + fibonacci(y + 3)

def solve(x, y, m):
    return f(x, y) % m

def main():
    assert(solve(11, 22, 10000) == 3072)

main()

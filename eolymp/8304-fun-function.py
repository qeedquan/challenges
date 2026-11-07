#!/usr/bin/env python3

"""

Find the value of the function

f(x, y) = 0                               x <= 0 or y <= 0
          f(x-1, y-2) + f(x-2, y-1) + 2   x <= y
          f(x-2, y-2) + 1                 x > y

Input
Given two integers x and y (0≤x,y≤50).

Output
Print the value of f(x,y).

Examples

Input #1
2 3

Answer #1
4

Input #2
34 12

Answer #2
6

"""

from functools import lru_cache

@lru_cache(maxsize=None)
def f(x, y):
    if x <= 0 or y <= 0:
        return 0
    if x <= y:
        return f(x-1, y-2) + f(x-2, y-1) + 2
    return f(x-2, y-2) + 1

def solve(x, y):
    return f(x, y)

def main():
    assert(solve(2, 3) == 4)
    assert(solve(34, 12) == 6)

main()


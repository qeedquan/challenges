#!/usr/bin/env python3

"""

Find the value of the function

f(x, y) = 1                          if x <= 0 or y <= 0
          f(x-1, y) + f(x, y-1) + 1  if x <= y
          f(x, y/2) + 2              if x > y

Input
Two integers x, y (0≤x,y≤25).

Output
Print the value of the function f(x,y).

Examples

Input #1
2 3

Answer #1
17

"""

from functools import lru_cache

@lru_cache(maxsize=None)
def f(x, y):
    if x <= 0 or y <= 0:
        return 1
    if x <= y:
        return f(x-1, y) + f(x, y-1) + 1
    return f(x, y//2) + 2

def solve(x, y):
    return f(x, y)

def main():
    assert(solve(2, 3) == 17)

main()

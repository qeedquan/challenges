#!/usr/bin/env python3

"""

Write a function that accepts two parameters (sum and multiply) and find two numbers [x, y], where x + y = sum and x * y = multiply.

Example:

sum = 12 and multiply = 32

In this case, x equals 4 and y equals 8.

x = 4

y = 8

Because

x + y = 4 + 8 = 12 = sum

x * y = 4 * 8 = 32 = multiply

The result should be [4, 8].

Note:

0 <= x <= 1000

0 <= y <= 1000

If there is no solution, your function should return null (or None in python).

You should return an array (list in python) containing the two values [x, y] and it should be sorted in ascending order.

One last thing: x and y are integers (no decimals).

"""

from math import isqrt

def solve(s, m):
    d = s**2 - 4*m
    x = (s - isqrt(d)) // 2
    y = abs(x - s)
    if d < 0 or x+y != s or x*y != m:
        return None
    return (x, y)

def main():
    assert(solve(12, 32) == (4, 8))
    assert(solve(13, 12) == (1, 12))
    assert(solve(6, 9) == (3, 3))
    assert(solve(200, 8452) == None)
    assert(solve(15, 56) == (7, 8))

main()

#!/usr/bin/env python3

"""

A Sturmian sequence is an infinite binary sequence satisfying two properties:

It is balanced. This can be stated a number of equivalent ways:
There is no pair of equal length subwords whose digit sums differ by 2 or more.
There is no string  w
  such that  0w0
  and  1w1
  are both subwords.
It is not eventually periodic. No (infinite) suffix of the sequence consists of a finite string repeated infinitely.
Your challenge is to output a Sturmian sequence of your own choosing. You may use any output method described by sequence.

This is code-golf, so the goal is to minimize the size of your source code as measured in bytes.

"""

from math import isqrt

# https://oeis.org/A003849
def sturmian(n):
    m = 5 * (n + 2)**2
    return 2 - (n + 2 + isqrt(m)>>1) + (n + 1 + isqrt(m - 10*n - 15)>>1)

def main():
    tab = [
        0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0,
        0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0,
        1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0,
        1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1,
        0, 0, 1
    ]

    for i in range(len(tab)):
        assert(sturmian(i) == tab[i])

main()

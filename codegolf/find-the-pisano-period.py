#!/usr/bin/env python3

"""

The Fibonacci sequence is a well know sequence in which each entry is the sum of the previous two and the first two entries are 1. If we take the modulo of each term by a constant the sequence will become periodic. For example if we took decided to compute the sequence mod 7 we would get the following:

1 1 2 3 5 1 6 0 6 6 5 4 2 6 1 0 1 1 ...
This has a period of 16. A related sequence, called the Pisano sequence, is defined such that a(n) is the period of the fibonacci sequence when calculated modulo n.

Task
You will should write a program or function that when given n will compute and output the period of the Fibonacci sequence mod n. That is the nth term in the Pisano sequence.

You must only support integers on the range 0 < n < 2^30

This is a code-golf competition so you should aim to minimize the size of your source code as scored by bytes.

Test cases
1  -> 1
2  -> 3
3  -> 8
4  -> 6
5  -> 20
6  -> 24
7  -> 16
8  -> 12
9  -> 24
10 -> 60
11 -> 10
12 -> 24

"""

from functools import *
from sympy import *

# https://oeis.org/A001175
def pisano(n):
    if n < 1:
        return 0
    if n == 1:
        return 1

    f = factorint(n)
    if len(f) > 1:
        return reduce(lcm, (pisano(a**f[a]) for a in f))

    k, x = 1, [1, 1]
    while x != [0, 1]:
        k += 1
        x = [x[1], (x[0] + x[1]) % n]
    return k

def main():
    tab = [
        1, 3, 8, 6, 20, 24, 16, 12, 24, 60, 10, 24, 28, 48, 40, 24, 36, 24, 18,
        60, 16, 30, 48, 24, 100, 84, 72, 48, 14, 120, 30, 48, 40, 36, 80, 24,
        76, 18, 56, 60, 40, 48, 88, 30, 120, 48, 32, 24, 112, 300, 72, 84, 108,
        72, 20, 48, 72, 42, 58, 120, 60, 30, 48, 96, 140, 120, 136
    ]

    for i in range(len(tab)):
        assert(pisano(i + 1) == tab[i])

main()

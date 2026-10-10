#!/usr/bin/env python3

"""

The evil professor has just given you the following task. Let us define a sequence as follows:

x[0] = 1
x[i] = x[floor(i - sqrt(i))] + x[floor(ln(i))] + x[floor(i*sin(i)^2)]

For each given value of i, compute xi.

Input
The input consists of multiple lines, each containing one integer i (0≤i≤10^6).
The last line contains −1 and should not be processed.

Output
For each value of i (except the last −1), print the corresponding value of xi modulo 10^6.

Examples

Input #1
0
1
2
10
-1

Answer #1
1
3
5
21

"""

from functools import lru_cache
from math import *

@lru_cache(maxsize=None)
def f(i):
    mod = 1000000

    if i < 0:
        return 0
    if i == 0:
        return 1

    i0 = int(floor(i - sqrt(i)))
    i1 = int(floor(log(i)))
    i2 = int(floor(i * sin(i)**2))
    return (f(i0) + f(i1) + f(i2)) % mod

def solve(n):
    return f(n)

def main():
    assert(solve(0) == 1)
    assert(solve(1) == 3)
    assert(solve(2) == 5)
    assert(solve(10) == 21)

main()


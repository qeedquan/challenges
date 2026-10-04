#!/usr/bin/env python3

"""

Echo numbers (A383896) are positive integers k such that the largest prime factor of k-1 is a suffix of k.

example
k = 4971 is an Echo number because k-1 = 4970 = 2*5*7*71 and k ends in 71

Here are the first Echo numbers:

13, 57, 73, 111, 127, 163, 193, 197, 313, 323, 337, 419, 433, 687, 757, 817, 847, 897, 929, 931, 973...

Input
A positive integer n

Output
The n-th Echo Number or the first n Echo numbers

n -> n-th Echo number
1 -> 13
10 -> 323
101 -> 17191
1015 -> 692231
10158 -> 23421249
0 or 1 indexed is allowed, just specify which one your code uses.

This is Code-Golf: shortest answer in bytes wins!

"""

from sympy import factorint

# https://oeis.org/A383896
def isecho(n):
    if n <= 2:
        return False
    s = str(n)
    t = str(max(factorint(n - 1)))
    return s.endswith(t)

def gen(n):
    r = []
    i = 1
    while len(r) < n:
        if isecho(i):
            r.append(i)
        i += 1
    return r

def main():
    tab = [
        13, 57, 73, 111, 127, 163, 193, 197, 313, 323, 337, 419, 433, 687, 757,
        817, 847, 897, 929, 931, 973, 1037, 1153, 1177, 1211, 1641, 2017, 2311,
        2593, 2623, 2647, 2913, 3073, 3137, 3659, 3661, 3829, 4031, 4117, 4213,
        4453, 4483, 4537, 4673, 4737, 4971, 5377, 5741
    ]

    assert(gen(len(tab)) == tab)

main()

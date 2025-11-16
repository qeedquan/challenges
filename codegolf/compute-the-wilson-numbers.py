#!/usr/bin/env python3

"""

Given a positive integer n, compute the nth Wilson number W(n) where

https://i.stack.imgur.com/eqSCC.png

and e = 1 if n has a primitive root modulo n, otherwise e = -1. In other words, n has a primitive root if there does not exist an integer x where 1 < x < n-1 and x2 = 1 mod n.

This is code-golf so create the shortest code for a function or program that computes the nth Wilson number for an input integer n > 0.
You may use either 1-based or 0-based indexing. You may also choose to output the first n Wilson numbers.
This is the OEIS sequence A157249.

Test Cases
n  W(n)
1  2
2  1
3  1
4  1
5  5
6  1
7  103
8  13
9  249
10 19
11 329891
12 32
13 36846277
14 1379
15 59793
16 126689
17 1230752346353
18 4727
19 336967037143579
20 436486
21 2252263619
22 56815333
23 48869596859895986087
24 1549256
25 1654529071288638505

"""

from math import *

# https://oeis.org/A157249
def wilson(n):
    if n < 1:
        return 0

    p = 1
    for i in range(1, n + 1):
        if gcd(i, n) == 1:
            p *= i
    return (p + 1) // n

def main():
    tab = [2, 1, 1, 1, 5, 1, 103, 13, 249, 19, 329891, 32, 36846277, 1379, 59793, 126689, 1230752346353, 4727, 336967037143579, 436486, 2252263619, 56815333, 48869596859895986087, 1549256, 1654529071288638505]

    for i in range(len(tab)):
        assert(wilson(i + 1) == tab[i])

main()

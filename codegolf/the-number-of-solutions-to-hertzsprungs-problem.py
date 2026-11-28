#!/usr/bin/env python3

"""

Hertzprung's Problem (OEIS A002464) is the number of solutions to a variant of the Eight Queens Puzzle, where instead of placing n queens, you place n rook-king fairy pieces (can attack like both a rook and a king);
in other words, it's how many possible positions you can place n rook-kings on an n×n board such that each piece does not occupy a neighboring square (both vertically, horizontally, and diagonally).

Challenge
Write the shortest function or full program that given a positive integer n>0 will output the non-negative number of solutions to Hertzprung's Problem A002464(n)≥0.

Notes

A formula is derived in this video:
https://www.youtube.com/watch?v=qt5I1gZj1ew

a(n) = n! + Sum_{k=1..n} (-1)^k * Sum_{t=1..k} binomial(k-1,t-1) * binomial(n-k,t) * 2^t * (n-k)!

Test Cases
1:  1
2:  0
3:  0
4:  2
5:  14
6:  90
23: 3484423186862152966838

"""

from math import *

# https://oeis.org/A002464
def hertzprung(n):
    v = factorial(n)
    for k in range(1, n+1):
        u = 0
        for t in range(1, k+1):
            u += comb(k-1, t-1) * comb(n-k, t) * 2**t * factorial(n-k)
        v += (-1)**k * u
    return v

def main():
    tab = [1, 1, 0, 0, 2, 14, 90, 646, 5242, 47622, 479306, 5296790, 63779034, 831283558, 11661506218, 175203184374, 2806878055610, 47767457130566, 860568917787402, 16362838542699862, 327460573946510746, 6880329406055690790, 151436547414562736234, 3484423186862152966838]

    for i in range(len(tab)):
        assert(hertzprung(i) == tab[i])

main()

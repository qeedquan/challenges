#!/usr/bin/env python3

from math import *

def coeff(n, m):
    return comb(n - 1, m - 1)

def solve():
    L = 10**60
    f = 1
    i = 1
    while f:
        for j in range(1, i+1):
            x = coeff(i, j)
            if x >= L:
                f = 0
            print(x, end=' ')
        print()
        i += 1

def main():
    solve()

main()

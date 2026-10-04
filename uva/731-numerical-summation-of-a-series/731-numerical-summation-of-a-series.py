#!/usr/bin/env python3

from scipy.special import *

def series(x):
    em = 0.57721566490153286060651209008240243104215933593992
    if x == 0:
        return zeta(2)
    return (em + digamma(x + 1)) / x

def solve():
    x = 0.0
    for i in range(3001):
        print("%6.2f %17.12f" % (x, series(x)))
        x += 0.1

def main():
    solve()

main()


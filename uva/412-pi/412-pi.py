#!/usr/bin/env python3

from math import *

def estimate(a):
    n = len(a)
    c = 0
    for i in range(0, n):
        for j in range(i+1, n):
            if gcd(a[i], a[j]) == 1:
                c += 1
    if c == 0:
        return "No estimate for this data set."
    
    x = n*(n-1)/2
    r = sqrt(6*x/c)
    return r

def test(a, r):
    p = estimate(a)
    print(p)
    if type(r) == float:
        assert(abs(p-r) < 1e-6)
    else:
        assert(p == r)

def main():
    test([2, 3, 4, 5, 6], 3.162278)
    test([13, 39], "No estimate for this data set.")

main()

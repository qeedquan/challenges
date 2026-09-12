#!/usr/bin/env python3

def solve(n):
    mod = 100000007
    r = 2**(n - 4)*n*(n**3 + 6*n**2 + 3*n - 2)
    r %= mod
    return r

def main():
    assert(solve(2) == 18)
    assert(solve(4) == 680)
    assert(solve(100) == 95856450)

main()


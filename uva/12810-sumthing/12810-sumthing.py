#!/usr/bin/env python3

def solve(a):
    mod = 1000000009
    div2 = pow(2, mod-2, mod)
    p = 1
    for x in a:
        p *= (1 + x*2)
        p %= mod
    p = ((p - 1) * div2) % mod
    return p

def main():
    assert(solve([1, 2, 3]) == 52)
    assert(solve([2, 3, 5, 7, 11]) == 66412)

main()

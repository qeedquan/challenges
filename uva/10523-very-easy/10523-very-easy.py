#!/usr/bin/env python3

def solve(n, a):
    r = 0
    for i in range(1, n+1):
        r += i * a**i
    return r

def main():
    assert(solve(3, 3) == 102)
    assert(solve(4, 4) == 1252)

main()


#!/usr/bin/env python3

def solve(n):
    return pow(66, n, 100)

def main():
    assert(solve(0) == 1)
    assert(solve(1) == 66)
    assert(solve(2) == 56)
    assert(solve(9999999999999999999999) == 36)

main()

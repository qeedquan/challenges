#!/usr/bin/env python3

def solve(n):
    if n < 0:
        return 0 
    if n <= 2:
        return 1
    return n**(n-2) % 2000000011

def main():
    assert(solve(1) == 1)
    assert(solve(2) == 1)
    assert(solve(3) == 3)

main()


#!/usr/bin/env python3

def solve(n, p):
    if n == 0:
        return 0
    return p % n

def main():
    assert(solve(4, 11) == 3)
    assert(solve(5, 111) == 1)

main()

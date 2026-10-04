#!/usr/bin/env python3

def solve(n, d):
    return n**d

def main():
    assert(solve(1, 20) == 1)
    assert(solve(3, 10) == 59049)

main()

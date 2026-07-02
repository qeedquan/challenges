#!/usr/bin/env python3

def solve(n, k):
    return k ^ (k >> 1)

def main():
    assert(solve(1, 0) == 0)
    assert(solve(1, 1) == 1)
    assert(solve(2, 0) == 0)
    assert(solve(2, 1) == 1)
    assert(solve(2, 2) == 3)
    assert(solve(2, 3) == 2)
    assert(solve(3, 0) == 0)
    assert(solve(3, 1) == 1)
    assert(solve(3, 2) == 3)
    assert(solve(3, 3) == 2)
    assert(solve(3, 4) == 6)
    assert(solve(3, 5) == 7)
    assert(solve(3, 6) == 5)
    assert(solve(3, 7) == 4)

main()

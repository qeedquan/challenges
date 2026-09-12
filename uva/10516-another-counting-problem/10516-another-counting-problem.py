#!/usr/bin/env python3

def solve(n, d):
    if n < 0 or d < 0:
        return 0

    a = 0
    b = 1
    for i in range(d):
        a = b
        b = b**n + 1
    return b - a

def main():
    assert(solve(2, 0) == 1)
    assert(solve(2, 1) == 1)
    assert(solve(2, 2) == 3)
    assert(solve(2, 3) == 21)
    assert(solve(3, 5) == 58871587162270592645034001)

main()


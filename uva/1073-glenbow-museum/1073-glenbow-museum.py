#!/usr/bin/env python3

# https://oeis.org/A002415
def solve(n):
    if n < 0 or n%2 != 0:
        return 0
    n //= 2
    return n**2 * (n**2 - 1) // 12

def main():
    assert(solve(4) == 1)
    assert(solve(6) == 6)

main()


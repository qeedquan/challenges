#!/usr/bin/env python3

def solve(n, b, d, m):
    # d * (b^n - 1) / (b - 1) mod m
    r = pow(b, n, (b-1)*m)
    r = (r + (b-1)*m - 1) // (b-1)
    r = (r * d) % m
    return r

def main():
    assert(solve(3, 10, 2, 10) == 2)

main()


#!/usr/bin/env python3

def solve(D, V):
    mod = 1000000007

    if D == 0:
        return 1
    if D == 1:
        return (V + 1) % mod
    if V == 1:
        return -1
    if V == 2:
        return (1 + D*2) % mod

    r = pow(V-1, D, mod) - 1 + mod
    r = (r * pow(V-2, mod-2, mod)) % mod
    r = (r * V) % mod
    r = (r + 1 + mod) % mod
    return r

def main():
    assert(solve(0, 1) == 1)
    assert(solve(1, 2) == 3)
    assert(solve(1, 5) == 6)
    assert(solve(500, 1) == -1)
    assert(solve(0, 500) == 1)
    assert(solve(2000000000, 2000000000) == 490156655)

main()


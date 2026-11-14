#!/usr/bin/env python3

def convb(n, b, p):
    if b < 1:
        return 0

    d = []
    while n > 0:
        d.append(n % b)
        n //= b
    
    r = 0
    for i in range(len(d)-1, -1, -1):
        r = (r * p) + d[i]
    return r

def solve(x, y, z):
    n = max(x, y, 36) + 1
    for i in range(1, n):
        a = convb(x, 10, i)
        b = convb(y, 10, i)
        c = convb(z, 10, i)
        if a+b == c:
            return i
    return 0

def main():
    assert(solve(5, 4, 10) == 9)
    assert(solve(155, 102, 301) == 6)
    assert(solve(1022, 221, 1303) == 4)
    assert(solve(6502, 6800, 11202) == 0)
    assert(solve(515, 7, 522) == 10)

main()


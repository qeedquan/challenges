#!/usr/bin/env python3

def oddsum(a, b):
    if b < a:
        a, b = b, a

    x = a // 2
    y = (b + 1) // 2
    return y**2 - x**2

def oddsumbf(a, b):
    if b < a:
        a, b = b, a

    if a%2 == 0 and a == b:
        return 0

    r = 0
    i = a
    while i <= b:
        if i%2 == 0:
            i += 1
        r += i
        i += 2
    return r

def main():
    assert(oddsum(0, 9) == 25)
    assert(oddsum(3, 9) == 24)
    assert(oddsum(1, 5) == 9)
    assert(oddsum(3, 5) == 8)

    n = 100
    for a in range(-n, n + 1):
        for b in range(-n, n + 1):
            assert(oddsum(a, b) == oddsumbf(a, b))

main()


#!/usr/bin/env python3

from math import gcd

def solve(H1, S1, H2):
    a = S1 * (H2 - 1)
    b = H1 - 1
    
    m = gcd(a, b)
    a //= m
    b //= m

    s = ""
    if a//b > 0:
        s += "%d" % (a//b)
    if a%b != 0:
        s += " %d/%d" % (a%b, b)
    return s.lstrip(" ")

def main():
    print(solve(6, 6, 12))
    print(solve(6, 6, 11))
    print(solve(3, 1, 2))

main()

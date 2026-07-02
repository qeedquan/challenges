#!/usr/bin/env python3

from math import sqrt

def solve(x):
    f = [0]*10
    f[0] = sqrt(2) + sqrt(3) + sqrt(6)
    for i in range(1, len(f)):
        f[i] = (f[i-1]**2 - 5) / (2*f[i-1] + 4)

    if x < 0:
        return 0
    if x < 3:
        return f[x]
    return f[4 - (x % 10)%2]

def main():
    print(solve(0))
    print(solve(1))

main()

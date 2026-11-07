#!/usr/bin/env python3

from math import factorial

def digits(n):
    d = [0] * 10
    while True:
        d[n % 10] += 1
        n //= 10
        if n == 0:
            break
    return d

def solve(n):
    d = digits(factorial(n))
    print(f"{n}! --")
    for i in range(10):
        print(f"\t({i})\t{d[i]}", end='')
        if i == 4:
            print()
    print()
    print()

def main():
    solve(3)
    solve(8)
    solve(100)
    solve(366)

main()

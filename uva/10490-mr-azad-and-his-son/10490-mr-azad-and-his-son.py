#!/usr/bin/env python3

from sympy import isprime

def solve(n):
    a = isprime(n)
    b = isprime((1 << n) - 1)
    if a and b:
        return "Perfect: %d!" % ((1<<(n-1)) * ((1<<n)-1))
    elif a and not b:
        return "Given number is prime. But, NO perfect number is available."
    return "Given number is NOT prime! NO perfect number is available."

def main():
    print(solve(2))
    print(solve(3))
    print(solve(6))

main()


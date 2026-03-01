#!/usr/bin/env python3

"""

Consider the number 1176 and its square (1176 * 1176) = 1382976. Notice that:

the first two digits of 1176 form a prime.
the first two digits of the square 1382976 also form a prime.
the last two digits of 1176 and 1382976 are the same.
Given two numbers representing a range (a, b), how many numbers satisfy this property within that range? (a <= n < b)

Example
solve(2, 1200) = 1, because only 1176 satisfies this property within the range 2 <= n < 1200. See test cases for more examples. The upper bound for the range will not exceed 1,000,000.

Good luck!

"""

from sympy import isprime

def satisfy(n):
    s1 = str(n)
    s2 = str(n * n)
    if len(s1) < 2 or len(s2) < 2:
        return False
    if not isprime(int(s1[:2])) or not isprime(int(s2[:2])):
        return False
    if s1[len(s1) - 2:] != s2[len(s2) - 2:]:
        return False
    return True

def solve(a, b):
    c = 0
    for i in range(a, b):
        if satisfy(i):
            c += 1
    return c

def main():
    assert(solve(2, 1200) == 1)
    assert(solve(1176, 1200) == 1)
    assert(solve(2, 100000) == 247)
    assert(solve(2, 1000000) == 2549)
    assert(solve(100000, 1000000) == 2302)

main()

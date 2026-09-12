#!/usr/bin/env python3

"""

Consider an array that has no prime numbers, and none of its elements has any prime digit. It would start with: [1,4,6,8,9,10,14,16,18,40,44..].

12 and 15 are not in the list because 2 and 5 are primes.

You will be given an integer n and your task will be return the number at that index in the array. For example:

solve(0) = 1
solve(2) = 6
More examples in the test cases.

Good luck!

"""

from sympy import isprime

# https://oeis.org/A062115
def noprimes(n):
    s = str(n)
    for i in range(len(s)):
        for j in range(i + 1, len(s) + 1):
            if isprime(int(s[i:j])):
                return False
    return True

def gen(n):
    r = []
    i = 0
    while len(r) < n:
        if noprimes(i):
            r.append(i)
        i += 1
    return r

def main():
    tab = [
        0, 1, 4, 6, 8, 9, 10, 14, 16, 18, 40, 44, 46, 48, 49, 60, 64, 66, 68,
        69, 80, 81, 84, 86, 88, 90, 91, 94, 96, 98, 99, 100, 104, 106, 108, 140,
        144, 146, 148, 160, 164, 166, 168, 169, 180, 184, 186, 188, 400, 404,
        406, 408, 440, 444, 446, 448, 460, 464, 466
    ]

    assert(gen(len(tab)) == tab)

main()

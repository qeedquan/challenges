#!/usr/bin/env python3

"""

Bertrand's postulate states that there is always at least 1 prime number between n and 2n for all n greater than 1.

Challenge
Your task is to take a positive integer n greater than 1 and find all of the primes between n and 2n (exclusive).

Any default I/O method can be used. Whoever writes the shortest code (in bytes) wins!

Test cases
n    2n     primes

2    4      3
7    14     11, 13
13   26     17, 19, 23
18   36     19, 23, 29, 31
21   42     23, 29, 31, 37, 41

"""

from sympy import *

# https://en.wikipedia.org/wiki/Bertrand%27s_postulate
def primes(n):
    return list(primerange(n + 1, 2 * n))

def main():
    assert(primes(2) == [3])
    assert(primes(7) == [11, 13])
    assert(primes(13) == [17, 19, 23])
    assert(primes(18) == [19, 23, 29, 31])
    assert(primes(21) == [23, 29, 31, 37, 41])

main()

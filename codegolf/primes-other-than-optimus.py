#!/usr/bin/env python3

"""

Challenge

Given an input integer n > 0, output the number of primes (other than n, if n itself is prime) that can be produced by altering one digit in the decimal expansion of n (without changing the number of digits).

Examples

For example, n = 2. By altering one digit in the decimal expansion of 2, we can come up with three additional prime numbers, 3, 5, 7, so a(n) = 3.

For another example, n = 13. By altering one digit, you can get primes 11, 17, 19, 23, 43, 53, 73, 83, so a(13) = 8.

For a final example, n = 20. By altering one digit, you can get primes 23, 29, so a(20) = 2.

Sequence

Here are the first 20 terms to get you started. This is OEIS A048853.

4, 3, 3, 4, 3, 4, 3, 4, 4, 4, 7, 4, 8, 4, 4, 4, 7, 4, 7, 2

Rules

The input and output can be assumed to fit in your language's native integer type.
The input and output can be given in any convenient format.
Ignore leading zeros (for example, 03 is not a prime number under this formulation).
Either a full program or a function are acceptable. If a function, you can return the output rather than printing it.
If possible, please include a link to an online testing environment so other people can try out your code!
Standard loopholes are forbidden.
This is code-golf so all usual golfing rules apply, and the shortest code (in bytes) wins.

"""

from sympy import *

def hamming1(n):
    s = str(n)
    d = "0123456789"
    for c in d:
        for i in range(len(s)):
            if c != s[i] and not (i == 0 and c == "0"):
                yield int(s[:i] + c + s[i+1:])

# https://oeis.org/A048853
def altering_primes(n):
    r = 0
    for i in hamming1(n):
        if isprime(i):
            r += 1
    return r

def main():
    tab = [4, 3, 3, 4, 3, 4, 3, 4, 4, 4, 7, 4, 8, 4, 4, 4, 7, 4, 7, 2, 7, 2, 6, 2, 2, 2, 7, 2, 5, 2, 5, 2, 8, 2, 2, 2, 5, 2, 7, 3, 6, 3, 7, 3, 3, 3, 6, 3, 8, 2, 7, 2, 6, 2, 2, 2, 7, 2, 5, 2, 5, 2, 8, 2, 2, 2, 5, 2, 7, 3, 6, 3, 7, 3, 3, 3, 8, 3, 6, 2, 7, 2, 6, 2, 2, 2, 7, 2, 5, 1, 6, 1, 7, 1, 1, 1, 4, 1, 6, 4, 10, 4, 8, 4, 4]

    for i in range(len(tab)):
        assert(altering_primes(i + 1) == tab[i])

main()

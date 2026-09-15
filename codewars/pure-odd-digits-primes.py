#!/usr/bin/env python3

"""

Primes that have only odd digits are pure odd digits primes, obvious but necessary definition.
Examples of pure odd digit primes are: 11, 13, 17, 19, 31...
If a prime has only one even digit does not belong to pure odd digits prime, no matter the  amount of odd digits that may have.

Create a function, only_oddDigPrimes(), that receive any positive integer n, and output a list like the one bellow:

[number pure odd digit primes bellow n, largest pure odd digit prime smaller than n, smallest pure odd digit prime higher than n]

Let's see some cases:

only_oddDigPrimes(20) ----> [7, 19, 31]
///7, beacause we have seven pure odd digit primes bellow 20 and are 3, 5, 7, 11, 13, 17, 19
19, because is the nearest prime of this type to 20
31, is the first pure odd digit that we encounter after 20///

only_oddDigPrimes(40) ----> [9, 37, 53]

In the case that n, the given value, is a pure odd prime, should be counted it with the found primes and search for the immediately bellow and the immediately after.

"""

from sympy import nextprime

def next_odd_digit_prime(p):
    while True:
        p = nextprime(p)
        s = str(p)
        if not ('0' in s or '2' in s or '4' in s or '6' in s or '8' in s):
            return p

# https://oeis.org/A030096
def odd_digit_primes(n):
    if n < 3:
        return [0, 0, 3]

    p = q = 3
    c = 1
    while True:
        p = next_odd_digit_prime(p)
        if p > n:
            break
        c += 1
        q = p
    return [c, q, p]

def main():
    assert(odd_digit_primes(20) == [7, 19, 31])
    assert(odd_digit_primes(40) == [9, 37, 53])
    assert(odd_digit_primes(55) == [10, 53, 59])
    assert(odd_digit_primes(60) == [11, 59, 71])
    assert(odd_digit_primes(100) == [15, 97, 113])

main()

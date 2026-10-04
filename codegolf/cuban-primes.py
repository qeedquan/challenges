#!/usr/bin/env python3

"""

Given a natural number n, return the n-th cuban prime.

Cuban Primes
A cuban prime is a prime number of the form

p = (x^3 - y^3) / (x - y)

where y>0 and x=1+y or x=2+y

Details
You may use 0 or 1 based indexing, whatever suits you best.
You can return the n-th prime given the index n or the first n primes in increasing order, or alternatively you can return an infinite list/generator that produces the primes in increasing order.

Test cases
The first few terms are following:

(#1-13)   7, 13, 19, 37, 61, 109, 127, 193, 271, 331, 397, 433, 547,
(#14-24) 631, 769, 919, 1201, 1453, 1657, 1801, 1951, 2029, 2269, 2437,
(#25-34) 2791, 3169, 3469, 3571, 3889, 4219, 4447, 4801, 5167, 5419,
(#35-43) 6211, 7057, 7351, 8269, 9241, 10093, 10267, 11719, 12097,
(#44-52) 12289, 13267, 13669, 13873, 16651, 18253, 19441, 19927, 20173

More terms can be found on OEIS: They are split up in two sequences, depending on wheter x=1+y or x=2+y: A002407 and A002648

"""

from sympy import isprime

# https://oeis.org/A002407
def gen(n):
    r, k, d = [], 1, 7
    while len(r) < n:
        if isprime(d):
            r.append(d)
        k += 1
        d = 1 + 3*k*(k + 1)
    return r

def main():
    tab = [7, 19, 37, 61, 127, 271, 331, 397, 547, 631, 919, 1657, 1801, 1951, 2269, 2437, 2791, 3169, 3571, 4219, 4447, 5167, 5419, 6211, 7057, 7351, 8269, 9241, 10267, 11719, 12097, 13267, 13669, 16651, 19441, 19927, 22447, 23497, 24571, 25117, 26227, 27361, 33391]

    assert(gen(len(tab)) == tab)

main()

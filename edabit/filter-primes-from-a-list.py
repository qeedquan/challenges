#!/usr/bin/env python3

"""

Create a function that takes a list and returns a new list containing only prime numbers.

Examples
filter_primes([7, 9, 3, 9, 10, 11, 27]) ➞ [7, 3, 11]

filter_primes([10007, 1009, 1007, 27, 147, 77, 1001, 70]) ➞ [10007, 1009]

filter_primes([1009, 10, 10, 10, 3, 33, 9, 4, 1, 61, 63, 69, 1087, 1091, 1093, 1097]) ➞ [1009, 3, 61, 1087, 1091, 1093, 1097]

Notes
New list must maintain the order of primes as they first appear in the original list.
Check the Resources tab for help.

"""

from sympy import *

def filterprimes(a):
    return list(filter(lambda x: isprime(x), a))

def main():
    assert(filterprimes([7, 9, 3, 9, 10, 11, 27]) == [7, 3, 11])
    assert(filterprimes([1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25]) == [2, 3, 5, 7, 11, 13, 17, 19, 23])
    assert(filterprimes([1009, 10, 10, 10, 3, 33, 9, 4, 1, 61, 63, 69, 1087, 1091, 1093, 1097]) == [1009, 3, 61, 1087, 1091, 1093, 1097])
    assert(filterprimes([10007, 1009, 1007, 27, 147, 77, 1001, 70]) == [10007, 1009])

main()

#!/usr/bin/env python3

"""

In this Kata, you will be given an integer array and your task is to return the sum of elements occupying prime-numbered indices.

The first element of the array is at index 0.

Good luck!

"""

from sympy import nextprime

def total(a):
    r = 0
    i = 2
    while i < len(a):
        r += a[i]
        i = nextprime(i)
    return r

def main():
    assert(total([]) == 0)
    assert(total([1, 2, 3, 4]) == 7)
    assert(total([1, 2, 3, 4, 5, 6]) == 13)
    assert(total([1, 2, 3, 4, 5, 6, 7, 8]) == 21)
    assert(total([1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]) == 21)
    assert(total([1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13]) == 33)
    assert(total([1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15]) == 47)

main()


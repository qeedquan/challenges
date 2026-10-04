#!/usr/bin/env python3

"""

Background
A number n can be described as B-rough if all of the prime factors of n strictly exceed B.

The Challenge
Given two positive integers B and k, output the first k B-rough numbers.

Examples
Let f(B, k) be a function which returns the set containing the first k B-rough numbers.

> f(1, 10)
1, 2, 3, 4, 5, 6, 7, 8, 9, 10

> f(2, 5)
1, 3, 5, 7, 9

> f(10, 14)
1, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59

"""

from sympy import *

def rough(B, k):
    if k < 1:
        return []

    r = [1]
    i = 2
    while len(r) < k:
        f = factorint(i)
        if all(x > B for x in f):
            r.append(i)
        i += 1
    return r

def main():
    assert(rough(1, 10) == [1, 2, 3, 4, 5, 6, 7, 8, 9, 10])
    assert(rough(2, 5) == [1, 3, 5, 7, 9])
    assert(rough(10, 14) == [1, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59])

main()

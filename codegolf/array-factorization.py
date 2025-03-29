#!/usr/bin/env python3

"""

Given an array of positive integers, output a stable array of the distinct prime factors of these integers. In other words, for each integer in the input in order, get its prime factors, sort them, and append any primes not already in the output to the output.

Test Cases
[1,2,3,4,5,6,7,8,9,10] -> [2,3,5,7]
[10,9,8,7,6,5,4,3,2,1] -> [2,5,3,7]
[100,99,98,1,2,3,4,5] -> [2,5,3,11,7]
[541,60,19,17,22] -> [541,2,3,5,19,17,11]
[1,1,2,3,5,8,13,21,34,45] -> [2,3,5,13,7,17]
[6,7,6,7,6,7,6,5] -> [2,3,7,5]
[1] -> []
[8] -> [2]
[] -> []

Output can be as an array or list of integers or strings, delimited output, or any other standard means of outputting an ordered list of numbers.

This is code-golf, so shortest answer in bytes wins.

"""

from sympy import *

def factor(a):
    r = []
    m = {}
    for v in a:
        p = list(factorint(v))
        p.sort()
        for x in p:
            if x not in m:
                r.append(x)
                m[x] = True
    return r

def main():
    assert(factor([1, 2, 3, 4, 5, 6, 7, 8, 9, 10]) == [2, 3, 5, 7])
    assert(factor([10, 9, 8, 7, 6, 5, 4, 3, 2, 1]) == [2, 5, 3, 7])
    assert(factor([100, 99, 98, 1, 2, 3, 4, 5]) == [2, 5, 3, 11, 7])
    assert(factor([541, 60, 19, 17, 22]) == [541, 2, 3, 5, 19, 17, 11])
    assert(factor([1, 1, 2, 3, 5, 8, 13, 21, 34, 45]) == [2, 3, 5, 13, 7, 17])
    assert(factor([6, 7, 6, 7, 6, 7, 6, 5]) == [2, 3, 7, 5])
    assert(factor([1]) == [])
    assert(factor([8]) == [2])
    assert(factor([]) == [])

main()

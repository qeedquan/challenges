#!/usr/bin/env python3

"""

This sequence is defined as

Starts with 1, 2, 3
The next element of the sequence is the first number greater than the previous three that is co-prime with each of the previous 3 elements in the sequence.
In other words, if the previous 3 elements are a, b, c, then the next is the first integer n>c such that gcd(a,n)=gcd(b,n)=gcd(c,n)=1.

This sequence on OEIS: OEIS

All elements below 100:

1,2,3,5,7,8,9,11,13,14,15,17,19,22,23,25,27,28,29,31,
33,34,35,37,39,41,43,44,45,47,49,52,53,55,57,58,59,61,
63,64,65,67,69,71,73,74,75,77,79,82,83,85,87,88,89,
91,93,94,95,97,99,

You can either:

Take a number as input, then output the Nth element in the sequence. Either 0 or 1 based is fine.
Take a number as input, then output the first N elements in this sequence.
Take no input, output the sequence infinitely.
Inspired by a discussion in chat

"""

from math import *

# https://oeis.org/A062062
def gen(n):
    r = [1, 2, 3]
    while len(r) < n:
        x = r[-1] + 1
        while gcd(r[-1], x) != 1 or gcd(r[-2], x) != 1 or gcd(r[-3], x) != 1:
            x += 1
        r.append(x)
    return r[:n]

def main():
    tab = [1, 2, 3, 5, 7, 8, 9, 11, 13, 14, 15, 17, 19, 22, 23, 25, 27, 28, 29, 31, 33, 34, 35, 37, 39, 41, 43, 44, 45, 47, 49, 52, 53, 55, 57, 58, 59, 61, 63, 64, 65, 67, 69, 71, 73, 74, 75, 77, 79, 82, 83, 85, 87, 88, 89, 91, 93, 94, 95, 97, 99, 101, 103, 104, 105, 107, 109, 113]
    
    assert(gen(len(tab)) == tab)

main()

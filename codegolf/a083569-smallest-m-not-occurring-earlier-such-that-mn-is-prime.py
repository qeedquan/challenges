#!/usr/bin/env python3

"""

Define a 1-indexed sequence as follows:

A083569(1) = 1
A083569(n) where n is an integer greater than 1, is the smallest integer m not occurring earlier such that m+n is a prime number.
Your task is to take in n and return A083569(n).

 n  A083569(n)
 1  1
 2  3
 3  2
 4  7
 5  6
 6  5
 7  4
 8  9
 9  8
10 13
11 12
12 11
13 10
14 15
15 14
16 21
17 20
18 19
19 18
20 17
More testcases can be found here. The original sequence on OEIS can be found here.

This is code-golf. Shortest answer in bytes wins. Standard loopholes apply.

"""

from sympy import *

# https://oeis.org/A083569
def gen(n):
    if n < 1:
        return []

    r = []
    i = 1
    while len(r) < n:
        p = nextprime(2*i - 1) - i + 1
        l = list(range(i, p))
        r += l[::-1]
        i = p
    return r[:n]

def main():
    tab = [
        1, 3, 2, 7, 6, 5, 4, 9, 8, 13, 12, 11, 10, 15, 14, 21, 20, 19, 18, 17,
        16, 25, 24, 23, 22, 27, 26, 31, 30, 29, 28, 35, 34, 33, 32, 37, 36, 41,
        40, 39, 38, 47, 46, 45, 44, 43, 42, 49, 48, 51, 50, 55, 54, 53, 52, 57,
        56, 69, 68, 67, 66, 65, 64, 63, 62, 61, 60, 59, 58, 79, 78, 77
    ]

    assert(gen(len(tab)) == tab)

main()

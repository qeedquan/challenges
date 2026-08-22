#!/usr/bin/env python3

"""

Consider having a cow that gives a child every year from her fourth year of life on and all her subsequent children do the same.

After n years how many cows will you have?

countCows(0); // should equal 1
countCows(1); // should equal 1
countCows(3); // should equal 2
countCows(4); // should equal 3
countCows(10);// should equal 28
Return null if n is not an integer.

Note: Assume all the cows are alive after n years.

"""

from math import comb
from functools import *

@lru_cache(maxsize=None)
def cowsrec(n):
    r = 1
    for i in range(3, n + 1):
        r += cows(n - i)
    return r

# https://oeis.org/A000930
def cows(n):
    r = 0
    for i in range(0, n//3 + 1):
        r += comb(n - 2*i, i)
    return r

def main():
    tab = [
        1, 1, 1, 2, 3, 4, 6, 9, 13, 19, 28, 41, 60, 88, 129, 189, 277, 406, 595,
        872, 1278, 1873, 2745, 4023, 5896, 8641, 12664, 18560, 27201, 39865,
        58425, 85626, 125491, 183916, 269542, 395033, 578949, 848491, 1243524,
        1822473, 2670964, 3914488, 5736961, 8407925
    ]

    for i in range(len(tab)):
        assert(cows(i) == tab[i])
        assert(cowsrec(i) == tab[i])

main()

#!/usr/bin/env python3

"""

In the poker game there are 1277 unique 'High Card' ranks. It's 1287 (13 over 5) if we include all straights.

The challenge is to write a function which returns an integer value corresponding to the rank of each 'High Card' poker combination including all straights. Possible cards are(in ascending order): '23456789TJQKA'

23456 -> 1
23457 -> 2
23467 -> 3
23567 -> 4
....
8JQKA -> 1285
9JQKA -> 1286
TJQKA -> 1287

"""

from itertools import combinations

def make_table():
    p = []
    for c in combinations("AKQJT98765432", 5):
        s = ''.join(c)[::-1]
        p.append(s)
    p = p[::-1]

    m = {}
    for i in range(len(p)):
        m[p[i]] = i + 1

    return m

TABLE = make_table()

def rank(s):
    global TABLE
    return TABLE[s]

def main():
    assert(rank("23456") == 1)
    assert(rank("23457") == 2)
    assert(rank("23467") == 3)
    assert(rank("23567") == 4)
    assert(rank("8JQKA") == 1285)
    assert(rank("9JQKA") == 1286)
    assert(rank("TJQKA") == 1287)

main()

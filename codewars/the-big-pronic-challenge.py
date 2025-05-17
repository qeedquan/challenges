#!/usr/bin/env python3

"""

A pronic number is a composite integer that is the product of two consecutive integers -- in other words, every pronic number can be calculated as either n(n+1) or n(n-1) where n is any integer. A related kata Figurate Numbers #2 - Pronic Number was fun and for the 32-bit integer problem space, a simple search-loop made solving that kata possible and a clever formula eliminated the need for a loop altogether.

This challenge will be different - this challenge is to write code that determines whether big -- REALLY BIG -- numbers are pronic. A naive loop through a billion or so numbers isn't going to work here. Provided is a non-loop based starter solution that generally works in the linked kata, but fails for the bigger data passed here.

Detail
The tests you see are all you need to pass. There are no surprise tests to pass after the original tests are passing.
These tests run your algorithm through over 300,000 numbers -- some pronic and some non-pronic. If your algorithm is reasonable, it should take considerably less than 6 seconds to complete.
While authoring this kata, a couple large valued test-cases produced calculated pronics that appeared to be either much smaller than they should have or in some cases they even resulted in negative values. This was due to overflow and unchecked math, so checked block safeguards have been added to the tests to prevent accidental overflow for new and existing test-cases.

"""

from math import isqrt

# https://oeis.org/A002378
def ispronic(n):
    x = isqrt(n)
    return x*(x + 1) == n

def main():
    tab = [
        0, 2, 6, 12, 20, 30, 42, 56, 72, 90, 110, 132, 156, 182, 210, 240, 272,
        306, 342, 380, 420, 462, 506, 552, 600, 650, 702, 756, 812, 870, 930,
        992, 1056, 1122, 1190, 1260, 1332, 1406, 1482, 1560, 1640, 1722, 1806,
        1892, 1980, 2070, 2162, 2256, 2352, 2450, 2550
    ]

    for i in range(max(tab) + 1):
        if i in tab:
            assert(ispronic(i) == True)
        else:
            assert(ispronic(i) == False)

main()

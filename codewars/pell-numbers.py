#!/usr/bin/env python3

"""

The Pell sequence is the sequence of integers defined by the initial values

P(0) = 0, P(1) = 1
and the recurrence relation

P(n) = 2 * P(n-1) + P(n-2)
The first few values of P(n) are

0, 1, 2, 5, 12, 29, 70, 169, 408, 985, 2378, 5741, 13860, 33461, 80782, 195025, 470832, ..
Task
Your task is to return the nth Pell number

"""

from math import sqrt

# https://oeis.org/A000129
def pell(n):
    if n < 0:
        return 0
    a = 1 + sqrt(2)
    b = 1 - sqrt(2)
    c = 2 * sqrt(2)
    return round((a**n - b**n) / c)

def main():
    tab = [
        0, 1, 2, 5, 12, 29, 70, 169, 408, 985, 2378, 5741, 13860, 33461, 80782,
        195025, 470832, 1136689, 2744210, 6625109, 15994428, 38613965, 93222358,
        225058681, 543339720, 1311738121, 3166815962, 7645370045, 18457556052,
        44560482149, 107578520350, 259717522849
    ]

    for i in range(len(tab)):
        assert(pell(i) == tab[i])

main()

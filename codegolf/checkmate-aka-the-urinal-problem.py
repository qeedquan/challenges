#!/usr/bin/env python3

"""

My Precalc teacher has one of his favorite problems that he made up (or more likely stole inspired by xkcd) that involves a row of n urinals. "Checkmate" is a situation in which every urinal is already occupied OR has an occupied urinal next to them. For instance, if a person is an X, then

X-X--X

is considered checkmate. Note that a person cannot occupy a urinal next to an already occupied urinal.

Task
Your program will take a number through stdin, command line args, or a function argument. Your program will then print out or return the number of ways that checkmate can occur in with the inputted number of urinals.

Examples
0 -> 1 (the null case counts as checkmate)
1 -> 1 (X)
2 -> 2 (X- or -X)
3 -> 2 (X-X or -X-)
4 -> 3 (X-X-, -X-X, or X--X)
5 -> 4 (X-X-X, X--X-, -X-X-, or -X--X)
6 -> 5 (X-X-X-, X--X-X, X-X--X, -X--X- or -X-X-X)
7 -> 7 (X-X-X-X, X--X-X-, -X-X--X, -X--X-X, X-X--X-, X--X--X or -X-X-X-)
8 -> 9 (-X--X--X, -X--X-X-, -X-X--X-, -X-X-X-X, X--X--X-, X--X-X-X, X-X--X-X, X-X-X--X, X-X-X-X-)
...

Scoring
The smallest program in bytes wins.

"""

from functools import *

# https://oeis.org/A228361
@lru_cache(maxsize=None)
def checkmate(n):
    lut = [0, 0, 1, 2, 2]
    if n < 0:
        return 0
    if n < len(lut):
        return lut[n]
    return checkmate(n - 2) + checkmate(n - 3)

def main():
    tab = [
        0, 0, 1, 2, 2, 3, 4, 5, 7, 9, 12, 16, 21, 28, 37, 49, 65, 86, 114, 151,
        200, 265, 351, 465, 616, 816, 1081, 1432, 1897, 2513, 3329, 4410, 5842,
        7739, 10252, 13581, 17991, 23833, 31572, 41824, 55405, 73396, 97229,
        128801, 170625, 226030, 299426, 396655, 525456
    ]

    for i in range(len(tab)):
        assert(checkmate(i) == tab[i])

main()

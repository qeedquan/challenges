#!/usr/bin/env python3

"""

Given a non-negative integer n, enumerate all palindromic numbers (in decimal) between 0 and n (inclusive range). A palindromic number remains the same when its digits are reversed.

The first palindromic numbers (in base 10) are given here:

0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 22, 33, 44, 55, 66, 77, 88, 99, 101, 111, 121, 131, 141, 151, 161, 171, 181, 191, 202, 212, 222, 232, 242, 252, 262, 272, 282, 292, 303, 313, 323, 333, 343, 353, 363, 373, 383, 393, 404, 414, 424, 434, 444, 454, 464, 474, 484, 494, 505, 515, ...

This is a code golf with the prize going to fewest characters. The palindromic numbers should be output one per line to stdout. The program should read n from the commandline or stdin.

"""

from math import log10, floor

# https://oeis.org/A002113
def palindrome(n):
    if n < 2:
        return 0

    P = 10**floor(log10(n//2))
    M = 11 * P

    s, i = "", -1
    if n < M:
        s = str(n - P)
        i = -2
    else:
        s = str(n - M + P)

    return int(s + s[i::-1])

def main():
    tab = [
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 11, 22, 33, 44, 55, 66, 77, 88, 99, 101,
        111, 121, 131, 141, 151, 161, 171, 181, 191, 202, 212, 222, 232, 242,
        252, 262, 272, 282, 292, 303, 313, 323, 333, 343, 353, 363, 373, 383,
        393, 404, 414, 424, 434, 444, 454, 464, 474, 484, 494, 505, 515
    ]

    for i in range(len(tab)):
        assert(palindrome(i + 1) == tab[i])

main()

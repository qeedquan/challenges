#!/usr/bin/env python3

"""

Given an integer n, output the first n sloping binary numbers, either 0- or 1-indexed. They are called this because of how they are generated:

Write numbers in binary under each other (right-justified):

........0
........1
.......10
.......11
......100
......101
......110
......111
.....1000
.........
Then, you need to take each diagonal from bottom-left to top-right, such that each final digit is the final digit of a diagonal. Here's the fourth diagonal (zero-indexed) marked with x's, which is 100:

........0
........1
.......10
.......11
......10x
......1x1
......x10
......111
.....1000
.........
The upward-sloping diagonals in order are:

0
11
110
101
100
1111
1010
.......
Then, convert to decimal, giving 0, 3, 6, 5, 4, 15, 10, ...

OEIS A102370

This is code-golf, so the shortest code in bytes wins.

"""

# https://oeis.org/A102370
def slopebin(n):
    if n < 1:
        return 0

    r = 0
    for k in range(len(bin(n)[2:]) + 1):
        r += (n + k) & (1 << k)
    return r

def main():
    tab = [0, 3, 6, 5, 4, 15, 10, 9, 8, 11, 14, 13, 28, 23, 18, 17, 16, 19, 22, 21, 20, 31, 26, 25, 24, 27, 30, 61, 44, 39, 34, 33, 32, 35, 38, 37, 36, 47, 42, 41, 40, 43, 46, 45, 60, 55, 50, 49, 48, 51, 54, 53, 52, 63, 58, 57, 56, 59, 126, 93, 76, 71, 66, 65, 64, 67, 70, 69]

    for i in range(len(tab)):
        assert(slopebin(i) == tab[i])

main()

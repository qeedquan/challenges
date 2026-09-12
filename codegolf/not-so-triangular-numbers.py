#!/usr/bin/env python3

"""

Let's consider the sequence S consisting of one 1 and one 0, followed by two 1's and two 0's, and so on:

1,0,1,1,0,0,1,1,1,0,0,0,1,1,1,1,0,0,0,0,...

(This is A118175: Binary representation of n-th iteration of the Rule 220 elementary cellular automaton starting with a single black cell.)

Given n>0, your task is to output a(n), defined as the number of 1's among the T(n) first terms of S,
where T(n) is the n-th triangular number.

The first few terms are:

1,2,3,6,9,11,15,21,24,28,36,42,46,55,65,70,78,91,99,105,...


One way to think of it is to count the number of 1's up to the n-th row of a triangle filled with the values of S:

1 (1)
01 (2)
100 (3)
1110 (6)
00111 (9)
100001 (11)
1111000 (15)
00111111 (21)
000000111 (24)
1111000000 (28)
01111111100 (36)
...
Rules
You may either:

take n as input and return the n-th term, 1-indexed take n as input and return the n-th term,
0-indexed take n as input and return the n first terms take no input and print the sequence forever
This is a code-golf challenge.

"""

from math import *

def triangular(n):
    return n * (n + 1) // 2

def check(n):
    if n < 0:
        return 0
    r = sqrt(n)
    return int(1 - ceil(r) + round(r))

# https://oeis.org/A338546
def seq(n):
    r = 0
    for i in range(1, triangular(n) + 1):
        if check(i) == 1:
            r += 1
    return r

def main():
    tab = [
        1, 2, 3, 6, 9, 11, 15, 21, 24, 28, 36, 42, 46, 55, 65, 70, 78, 91, 99,
        105, 120, 133, 140, 153, 171, 180, 190, 210, 225, 234, 253, 275, 285,
        300, 325, 341, 352, 378, 402, 414, 435, 465, 481, 496, 528, 553, 567,
        595, 630, 645, 666, 703, 728, 744, 780, 816
    ]

    for i in range(len(tab)):
        assert(seq(i + 1) == tab[i])

main()

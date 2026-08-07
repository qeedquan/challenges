#!/usr/bin/env python3

"""

For any integer r, there exists a power of 2 each of whose last r digits are either 1 or 2.

Given r, find the smallest x such that 2^x mod 10^r consists of only 1 or 2.

For r=2, x=9, since 2^9=512

For r=3, x=89, since 2^89=618970019642690137449562112

Note: for r=4, x is=89 (again)

Input : r≤100

Output : x

Eg.

Input : 2
Ouput : 9

Input : 3
Ouput : 89

The program should run in a reasonable amount of time.

EDIT: The oeis sequence for this challenge is A147884.

"""

from itertools import count, islice
from sympy import discrete_log

# https://oeis.org/A147884
def gen():
    a, b, c = 0, 1, 1
    for n in count(0):
        if (a>>n)&1 != 0:
            a += b * c
        else:
            a += (b * c) << 1
        c *= 5
        yield int(discrete_log(c, a, 2))
        b <<= 1

def main():
    tab = [
        1, 9, 89, 89, 589, 3089, 3089, 3089, 315589, 315589, 8128089, 164378089,
        945628089, 1922190589, 11687815589, 109344065589, 231414378089,
        1452117503089, 4503875315589, 65539031565589, 141832976878089,
        1667711883128089, 3575060515940589
    ]

    assert(list(islice(gen(), len(tab))) == tab)

main()

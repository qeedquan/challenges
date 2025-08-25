#!/usr/bin/env python3

"""

It happened in the 19th century. Georg was bored and started counting the rational numbers. Surprisingly, he discovered that there were no more of them than natural numbers. This insight made Georg famous. (OEIS A352911, only added in 2022!)

But was Georg right? He didn't even count half of the fractions! He left the others aside. The part that nobody needs because they can be reduced to a simpler form. There are a lot more of them! Or are there not? We have to check and recount this part of the fractions.

Challenge

Write a function that enumerates the pairs (i, j) of noncoprime positive integers sorted first by i + j then by i.

We write them one after the other, numerator, denominator, without a pair of brackets and without the '/' sign.

Rules

Standard I/O rules apply and no standard loopholes.

This is code-golf, so the shortest code in bytes wins.

"""

from math import gcd
from itertools import chain, count, islice

# https://oeis.org/A352911
def gen():
    return chain.from_iterable((i, n - i) for n in count(2) for i in range(1, n) if gcd(i, n - i) == 1)

def main():
    tab = [
        1, 1, 1, 2, 2, 1, 1, 3, 3, 1, 1, 4, 2, 3, 3, 2, 4, 1, 1, 5, 5, 1, 1, 6,
        2, 5, 3, 4, 4, 3, 5, 2, 6, 1, 1, 7, 3, 5, 5, 3, 7, 1, 1, 8, 2, 7, 4, 5,
        5, 4, 7, 2, 8, 1, 1, 9, 3, 7, 7, 3, 9, 1, 1, 10, 2, 9, 3, 8, 4, 7, 5,
        6, 6, 5, 7, 4, 8, 3, 9, 2, 10, 1, 1, 11, 5, 7, 7, 5, 11, 1
    ]
    
    assert(list(islice(gen(), len(tab))) == tab)

main()

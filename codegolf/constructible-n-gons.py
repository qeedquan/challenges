#!/usr/bin/env python3

"""

A constructible n-gon is a regular polygon with n sides that you can construct with only a compass and an unmarked ruler.

As stated by Gauss, the only n for which a n-gon is constructible is a product of any number of distinct Fermat primes and a power of 2
(ie.  n=2k×p1×p2×... with  k being an integer and every pi some distinct Fermat prime).

A Fermat prime is a prime which can be expressed as  2^(2^(n+1)) with n a positive integer. The only known Fermat primes are for  n=0,1,2,3 and 4

The challenge
Given an integer n>2, say if the n-gon is constructible or not.

Specification
Your program or function should take an integer or a string representing said integer
(either in unary, binary, decimal or any other base) and return or print a truthy or falsy value.

This is code-golf, so shortest answer wins, standard loopholes apply.

Relevant OEIS

Examples
3 -> True
9 -> False
17 -> True
1024 -> True
65537 -> True
67109888 -> True
67109889 -> False

"""

from sympy import totient

# https://oeis.org/A003401
def constructable(n):
    if n < 1:
        return False
    return int(totient(n)).bit_count() == 1

def gen(n):
    r = []
    i = 0
    while len(r) < n:
        if constructable(i):
            r.append(i)
        i += 1
    return r

def main():
    tab = [
        1, 2, 3, 4, 5, 6, 8, 10, 12, 15, 16, 17, 20, 24, 30, 32, 34, 40, 48,
        51, 60, 64, 68, 80, 85, 96, 102, 120, 128, 136, 160, 170, 192, 204,
        240, 255, 256, 257, 272, 320, 340, 384, 408, 480, 510, 512, 514, 544,
        640, 680, 768, 771, 816, 960, 1020, 1024, 1028, 1088, 1280, 1285
    ]

    assert(constructable(3) == True)
    assert(constructable(9) == False)
    assert(constructable(17) == True)
    assert(constructable(1024) == True)
    assert(constructable(65537) == True)
    assert(constructable(67109888) == True)
    assert(constructable(67109889) == False)

    assert(gen(len(tab)) == tab)

main()

#!/usr/bin/env python3

"""

A superabundant number is an integer n that sets a new upper bound for its ratio with the divisor sum function σ. In other words, n is superabundant if and only if, for all positive integers x that are less than n:

σ(n)/n > σ(x)/x

For a few of the values:

n   σ(n)   σ(n)/n   superabundant
1   1      1.0000   yes
2   3      1.5000   yes
3   4      1.3333   no
4   7      1.7500   yes
5   6      1.2000   no
6   12     2.0000   yes
7   8      1.1429   no
8   15     1.8750   no
9   13     1.4444   no
A longer list of these (for test cases) can be found at OEIS A004394.

One highly recommended negative test case (if your interpreter can handle it) is 360360, because it ties with the last superabundant number.

Challenge
Your program should take in a single positive integer, and output a truthy or falsey value representing whether that integer is superabundant.

As this is code-golf, the shortest answer in bytes wins.

"""

from sympy import divisor_sigma

# https://oeis.org/A004394
def super_abundant(n):
    if n < 1:
        return False
    sn = divisor_sigma(n)
    for i in range(1, n):
        sm = divisor_sigma(i)
        if sm*n >= sn*i:
            return False
    return True

def gen(n):
    r = []
    i = 1
    while len(r) < n:
        if super_abundant(i):
            r.append(i)
        i += 1
    return r

def main():
    tab = [1, 2, 4, 6, 12, 24, 36, 48, 60, 120, 180, 240, 360, 720, 840, 1260, 1680, 2520, 5040]

    assert(gen(len(tab)) == tab)
    assert(super_abundant(360360) == False)

main()

#!/usr/bin/env python3

"""

We have a challenge to calculate the hyperfactorial and one to count the trailing zeros of the factorial, so it seems logical to put them together and count the trailing zeros in the hyperfactorial.

As a recap, the hyperfactorial of a number, H(n) is simply Πiⁱ, that is, 1¹·2²·3³·4⁴·5⁵·…·nⁿ. It can be defined recursively as H(n) = nⁿH(n-1) with H(0) = 1. This is integer sequence A002109.

Your task is to write the shortest program or function that accepts a non-negative integer n and returns or prints the number of trailing zeros in H(n) when represented as a decimal number (i.e. the corresponding entry from sequence A246839).

n will be in the range of integers in your language; H(n) might not be. That means your program must terminate given any non-negative n that's valid in your language (or 2³² if that's smaller).

Some test cases:

input	output
0	0
4	0
5	5
10	15
24	50
25	100
250	8125
10000 12518750

"""

"""

https://oeis.org/A246839

@loopywait:

How?
Calculates the number almost directly only recursing to correct for higher powers of 5 in the base:

f(n) = Sum[i=5, 10, ..., n] i + Sum[i=25, 50, ..., n] i + Sum[i=125, 250, ..., n] i + ...
f(n) = 5^([floor(n/5) * (floor(n/5) + 1)]/2) + 5 * f(floor(n/5))

"""

def hftz(n):
    if n == 0:
        return 0
    m = n // 5
    return (hftz(m) + m*(m + 1)//2) * 5

def main():
    tab = [
        0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 15, 15, 15, 15, 15, 30, 30, 30, 30, 30,
        50, 50, 50, 50, 50, 100, 100, 100, 100, 100, 130, 130, 130, 130, 130,
        165, 165, 165, 165, 165, 205, 205, 205, 205, 205, 250, 250, 250, 250,
        250, 350, 350, 350, 350, 350, 405, 405, 405, 405
    ]

    for i in range(len(tab)):
        assert(hftz(i) == tab[i])

    assert(hftz(0) == 0)
    assert(hftz(4) == 0)
    assert(hftz(5) == 5)
    assert(hftz(10) == 15)
    assert(hftz(24) == 50)
    assert(hftz(25) == 100)
    assert(hftz(250) == 8125)
    assert(hftz(10000) == 12518750)

main()

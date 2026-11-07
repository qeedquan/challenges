#!/usr/bin/env python3

"""

Description
In mathematics, and more specifically number theory, the hyperfactorial of a positive integer n is the product of the numbers 1^1, 2^2, ..., n^n:

H(n) = Product[i=1, n] i^i

Check out this Wikipedia article for more detail
https://en.wikipedia.org/wiki/Hyperfactorial

Your task
Implement a function hyperfact(num) that takes a positive integer num and returns the hyperfactorial of it.

In order for your answer not to be too messy (hyperfactorial of 100 is 9015 digits long) give the answer modulo 1000000007.

Notes
1 <= n <= 300

50 random tests

"""

# https://oeis.org/A002109
def hyperfactorial(n):
    if n < 1:
        return 0

    m = 1000000007
    r = 1
    for i in range(2, n + 1):
        r = (r%m * (i**i)%m) % m
    return r

def main():
    assert(hyperfactorial(1) == 1)
    assert(hyperfactorial(2) == 4)
    assert(hyperfactorial(3) == 108)
    assert(hyperfactorial(4) == 27648)
    assert(hyperfactorial(5) == 86400000)
    assert(hyperfactorial(6) == 78371783)
    assert(hyperfactorial(7) == 532835375)
    assert(hyperfactorial(8) == 116239542)
    assert(hyperfactorial(9) == 887540985)
    assert(hyperfactorial(10) == 872131491)
    assert(hyperfactorial(300) == 19936859)

main()

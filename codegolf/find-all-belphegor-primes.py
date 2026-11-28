#!/usr/bin/env python3

"""

A Belphegor number is a number of the form (10^(n+3) + 666) ∗ 10^(n+1) + 1 (1{n zeroes}666{n zeroes}1) where n is an non-negative integer. A Belphegor prime is a Belphegor number that is also prime.

The n values of the first few Belphegor primes are 0, 13, 42, 506 (A232448)

Task
Write a program that either:

takes no input and outputs all Belphegor primes.
takes a input k and outputs the first k Belphegor primes.
A reference python implementation can be found here.
https://tio.run/##VY5BCsMgEEX3nmKgG01LaAhkUcgtcoKWsQpxRtQsPL21MaR0FrP4//3543MyTGMp1nkOCWzCkJjXKHRgBzE7n3tKBjnk3gfrMGGs2EHHXRJCcwACS798/@KNklQPAXWeuHqD70rNIId710mCK4yqrmmaFHRwisNXHMQe26/XyNEjzzOq@VY3pJUcidp6cjfQ6xbNvIQNFcAF6gcNoT@rlA8

Rules
You may output the n value for the Belphegor prime instead of the prime itself
You may use probabilistic primality tests as long as there is no known counter case.

Scoring
This is code-golf so shortest bytes wins.

Inspired by The Most Evil Number - Numberphile

"""

import itertools
from sympy import *

def gen(n):
    result = []
    i = 0
    while len(result) < n:
        belphegor = (10**(i + 3) + 666) * 10**(i + 1) + 1
        prime = isprime(belphegor)
        if prime:
            result.append(belphegor)
        i += 1
    return result

def main():
    print(gen(4))

main()

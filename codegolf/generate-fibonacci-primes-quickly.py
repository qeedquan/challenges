#!/usr/bin/env python3

"""

Unsurprisingly, fibonacci primes are primes that are also Fibonacci numbers. There are currently 34 known Fibonacci primes and an additional 15 probable Fibonacci primes.
For the purpose of this challenge, the Fibonacci numbers are the sequence Fn defined as F1=1 , F2=1, and Fn=Fn−1+Fn−2, and a number is considered prime if it passes a probabilistic prime test with a probability of being incorrect of less than 2^-32.
For example, since a k round Miller-Rabin test has an error probability of 4^-k, a 16 round Miller-Rabin test is sufficient to prove primality for the purpose of this challenge.

Submissions:
The goal of this challenge is to write a full program that calculates every Fibonacci prime and its index in the Fibonacci series as fast as possible.

Submissions shall be a full program, complete with instructions for building and running it.
Submissions must be in a language freely available for noncommercial use and capable of running on Windows 10, and users must be prepared to provide installation instructions for that language.
External libraries are permitted, with the same caveats that apply to languages.

Primes will be output by writing them as base 10 integers to stdout in ascending order in the format index,prime\n where \n is the newline character. The numbers can have extraneous leading/trailing whitespace other than the newline character.

Scoring
The programs will be run on an Intel(R) Core(TM) i5-8365U CPU with 8 threads, avx-2 support, and 24 Gigabytes of ram. The largest prime that can be correctly reached in one minute wins. Tiebreaker is the time taken to reach the largest value. Programs that tamper with my computer or the testing program will be disqualified. Programs that error or otherwise fail to produce the correct output will be judged based on the furthest Fibonacci prime reached before they failed.

see also: A005478, A001605

"""

from sympy import *

# https://oeis.org/A005478
# https://oeis.org/A001605
def fibprime(n):
    r, a, b, i = [], 0, 1, 0
    while len(r) < n:
        if isprime(a):
            r.append((i, a))
        a, b, i = b, a + b, i + 1
    return r

def main():
    F = [2, 3, 5, 13, 89, 233, 1597, 28657, 514229, 433494437, 2971215073, 99194853094755497, 1066340417491710595814572169, 19134702400093278081449423917, 475420437734698220747368027166749382927701417016557193662268716376935476241]
    I = [3, 4, 5, 7, 11, 13, 17, 23, 29, 43, 47, 83, 131, 137, 359]

    x = fibprime(len(F))
    for i in range(len(x)):
        assert(x[i][0] == I[i])
        assert(x[i][1] == F[i])

main()

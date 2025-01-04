#!/usr/bin/env python3

"""

Given n, k, and p, find the probability that a weighted coin with probability p of heads will flip heads at least k times in a row in n flips,
correct to 3 decimal digits after decimal point (changed from 8 because I don't know how to estimate the accuracy of double computation for this (was using arbitrary precision floating points before)).

Edits:

Examples:

n, k, p     -> Output
10, 3, 0.5  -> 0.5078125
100, 6, 0.6 -> 0.87262307
100, 9, 0.2 -> 0.00003779

"""

from math import *

"""

https://math.stackexchange.com/questions/59738/probability-for-the-length-of-the-longest-run-in-n-bernoulli-trials

This problem was solved using generating functions by de Moivre in 1738.

References

Section 14.1 Problems and Snapshots from the World of Probability by Blom, Holst, and Sandell

Chapter V, Section 3 Introduction to Mathematical Probability by Uspensky

Section 22.6 A History of Probability and Statistics and Their Applications before 1750 by Hald gives solutions by de Moivre (1738), Simpson (1740), Laplace (1812), and Todhunter (1865)

"""
def probability(n, k, p):
    r = 0
    for j in range(1, n//k + 1):
        s = (-1)**(j+1)
        a = p + (1-p)*(n - j*k + 1)/j
        b = comb(n - j*k, j - 1)
        c = p**(j*k) * (1-p)**(j-1)
        r += s*a*b*c
    return r

def test(n, k, p, r):
    v = probability(n, k, p)
    print(v)
    assert(abs(v-r) < 1e-7)

test(10, 3, 0.5, 0.5078125)
test(100, 6, 0.6, 0.87262307)
test(100, 9, 0.2, 0.00003779)

#!/usr/bin/env python3

"""

Write a program that computes the Kaprekar chain for a given starting number, and compute the longest possible Kaprekar chain

"""

# 123 -> [1, 2, 3]
def digits(n, base=10):
    ds = []
    while n > 0:
        ds.insert(0, n % base)
        n //= base
    return ds

# [1, 2, 3] -> 123
def revdigits(ds, base=10):
    n = 0
    for i in ds:
        n = n * base + i
    return n

# returns the difference between the descending and
# ascending sorted lists of an integer's digits
def kaprekar(n, base=10):
    ds = sorted(digits(n, base))
    ds = [y - x for (x, y) in zip(ds, ds[::-1])]
    return revdigits(ds, base)

# returns a 2-tuple containing the initial convergation
# and the cyclic part of a Kaprekar chain
def findchain(n, base=10):
    chain = []
    while True:
        if n in chain:
            # loop found
            i = chain.index(n)
            return (chain[:i], chain[i:])
        chain.append(n)
        n = kaprekar(n, base)

"""

Ported from reddit user

https://mathworld.wolfram.com/KaprekarRoutine.html

"""
def main():
    init, cycle = findchain(39964)
    print("Init:", init)
    print("Cycle:", cycle)

main()

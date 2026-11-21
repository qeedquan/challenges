#!/usr/bin/env python3

"""

Combinations are a way to count the number of unordered subsets of a set

nCr = binomial(n, r)

Some properties:

nCr * r! = nPr
From this we know that nCr <= nPr

"""

from math import *

"""

How many ways can 2 people be selected from 4 to go to a concert?

If using nPr, then (4)P(2) = 4!/(4-2)! = 24/2 = 12
This is one way to solve it by counting the number of ordered subsets (sampling without replacement)

Another way to solve this problem is to count the number of *unordered* subsets of size r and permute them to get the number of ordered subsets:
This is nCr * r! = nPr

"""
def problem1():
    return comb(4, 2)*factorial(2)

"""

Twelve (12) patients are available for use in a research study. Only seven (7) should be assigned to receive the study treatment.
How many different subsets of seven patients can be selected?

(12)C(7)

"""
def problem2():
    return comb(12, 7)

"""

Let's use a standard deck of cards containing 13 face values (Ace, 2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, and King) and 4 different suits (Clubs, Diamonds, Hearts, and Spades) to play five-card poker. If you are dealt five cards, what is the probability of getting a "full-house" hand containing three kings and two aces (KKKAA)?

Count up the possibilities of a full-house hands divided by the total number of possibilities of all cards
This is unordered in this case so we use combinations

P(KKKAA) = n(KKKAA) / n(5)

Since we have 5 cards out of 52 cards, we can pull out
n(5) = comb(52, 5)

Since there are 4 kings possible and we want to pull out 3 kings, there are comb(4, 3) ways
Same logic applies to the aces, comb(4, 2) so combine them to get
n(KKKAA) = comb(4, 3)*comb(4,2)

"""
def problem3():
    return comb(4, 3)*comb(4, 2) / comb(52, 5)

"""

If you are dealt five cards, what is the probability of getting any full-house hand?

P(FH) = n(FH)/n(5)

"""
def problem4():
    return comb(13, 1)*comb(4, 3)*comb(12, 1)*comb(4, 2) / comb(52, 5)

def main():
    print(problem1())
    print(problem2())
    print(problem3())
    print(problem4())

main()

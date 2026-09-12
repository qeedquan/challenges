#!/usr/bin/env python3

"""

This is not a duplicate of Sum of combinations with repetition. This question considers 1+2 to be the same as 2+1. The other question doesn't.

OEIS link - A000008

Background
If you have 4 types of coins (1, 2, 5 and 10 cents), in how many ways can you make an amount?

There are 4 ways of making 5 cents:

1 + 1 + 1 + 1 + 1
1 + 1 + 1 + 2
1 + 2 + 2
5
Note: 1 + 2 + 2 and 2 + 2 + 1 are considered to be the same in this challenge.

Your task
Take an input. It will be a positive integer. This is the amount (in cents).
Work out the number of ways to make that number from 1, 2, 5 and 10 cent coins.
This is a sequence challenge, so any form of output is allowed.
This is code-golf, so shortest answer in bytes wins.

"""

from sympy import symbols

# https://oeis.org/A000008
def seq(n):
    if n < 0:
        return 0
    if n == 0:
        return 1
    
    x = symbols('x')
    G = 1 / ((1 - x) * (1 - x**2) * (1 - x**5) * (1 - x**10))
    return G.series(x, 0, n + 1).coeff(x, n)

def main():
    tab = [
        1, 1, 2, 2, 3, 4, 5, 6, 7, 8, 11, 12, 15, 16, 19, 22, 25, 28, 31, 34,
        40, 43, 49, 52, 58
    ]

    for i in range(len(tab)):
        assert(seq(i) == tab[i])

main()

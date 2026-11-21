#!/usr/bin/env python3

"""

Gozinta Chains
(Inspired by Project Euler #606)

A gozinta chain for n is a sequence {1,a,b,...,n} where each element properly divides the next. For example, there are eight distinct gozinta chains for 12:

{1,12}, {1,2,12}, {1,2,4,12}, {1,2,6,12}, {1,3,12}, {1,3,6,12}, {1,4,12} and {1,6,12}.
The Challenge
Write a program or function that accepts a positive integer (n > 1) and outputs or returns all the distinct gozinta chains for the given number.

Order in the chains matters (ascending), order of the chains does not.
On the off-chance it exists, you cannot use a builtin that solves the challenge.
This is code-golf.
Edit: Removing 1 as a potential input.

"""

# https://oeis.org/A002033 (length of the chain)
def gozinta(x):
    result = []
    for divisor in range(1, x):
        if x % divisor == 0:
            for sequence in gozinta(divisor):
                result.append(sequence + [x])
    return result or [[x]]

def main():
    A002033 = [
        1, 1, 1, 2, 1, 3, 1, 4, 2, 3, 1, 8, 1, 3, 3, 8, 1, 8, 1, 8, 3, 3, 1, 20,
        2, 3, 4, 8, 1, 13, 1, 16, 3, 3, 3, 26, 1, 3, 3, 20, 1, 13, 1, 8, 8, 3,
        1, 48, 2, 8, 3, 8, 1, 20, 3, 20, 3, 3, 1, 44, 1, 3, 8, 32, 3, 13, 1, 8,
        3, 13, 1, 76, 1, 3, 8, 8, 3, 13, 1, 48, 8, 3, 1, 44, 3, 3, 3, 20, 1, 44,
        3, 8, 3, 3, 3, 112
    ]

    for i in range(len(A002033)):
        assert(len(gozinta(i + 1)) == A002033[i])

main()

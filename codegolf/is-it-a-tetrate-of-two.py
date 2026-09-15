#!/usr/bin/env python3

"""

The tetration operation consists of repeated exponentiation, and it is written ↑↑. For instance,

3↑↑3 =3 ^(3^3) = 3^27 = 7,625,597,484,987
A tetrate of two is an integer that is equal to 2↑↑n for some nonnegative integer n. As an edge case, we say that 2↑↑0=1.

In this challenge, you will be given a positive integer as input, and you must output whether the integer is a tetrate of two.

The list of tetrates of two is:

1, 2, 4, 16, 65536, 2^65536, ...
This sequence is OEIS A014221.

Your answer need only give the correct answer up to the limits of your datatype and/or addressable memory, but your algorithm should be theoretically correct for all inputs.

You must take an integer as input and output whether it is a terate of two. Outputting the sequence of tetrates of two is not allowed.

All standard input and output methods are allowed. Standard output distinctions for decision problems are allowed: truthy/falsy or any two consistent results.

This is code golf: shortest program in each language wins.

Bonus challenge: There is an extremely short solution for this challenge in Pyth. Whenever a Pyth solution is posted, I'll let you know whether a shorter solution exists. If and when someone matches or beats my program, I'll give them a 200 point bounty.

"""

# https://oeis.org/A014221
def tetrate2(n):
    x = 0
    while x < n:
        x = 2**x
    return x == n

def main():
    tab = [0, 1, 2, 4, 16, 65536]
    for i in range(max(tab) + 1):
        if tetrate2(i):
            assert(i in tab)
        else:
            assert(i not in tab)

main()

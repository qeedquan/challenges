#!/usr/bin/env python3

"""

Challenge description
A Smith number is a composite number whose sum of digits is equal to the sum of sums of digits of its prime factors. Given an integer N, determine if it's a Smith number or not.

The first few Smith numbers are 4, 22, 27, 58, 85, 94, 121, 166, 202, 265, 274, 319, 346, 355, 378, 382, 391, 438 (sequence A006753 in OEIS).

Sample input / output
18: False (sum of digits: 1 + 8 = 9; factors: 2, 3, 3; sum of digits of factors: 2 + 3 + 3 = 8)
22: True
13: False (meets the digit requirement, but is prime)
666: True (sum of digits: 6 + 6 + 6 = 18; factors: 2, 3, 3, 37; sum of digits of factors: 2 + 3 + 3 + 3 + 7 = 18)
-265: False (negative numbers can't be composite)
0: False (not composite)
1: False (not composite)
4937775: True

Notes
Your code can be a function (method) or a full working program,
Instead of words like True and False, you can use any truthy and falsy values, as long as it's clear what they are,
This is a code-golf challenge, so make your code as short as possible!

"""

from sympy import factorint

def sd(n):
    return sum(map(int, str(n)))

# https://oeis.org/A006753
def smith(n):
    if n < 0:
        return False
    f = factorint(n)
    return sum(f[p] for p in f) > 1 and sd(n) == sum(sd(p)*f[p] for p in f)


def main():
    assert(smith(18) == False)
    assert(smith(22) == True)
    assert(smith(13) == False)
    assert(smith(666) == True)
    assert(smith(-265) == False)
    assert(smith(0) == False)
    assert(smith(1) == False)
    assert(smith(4937775) == True)

main()

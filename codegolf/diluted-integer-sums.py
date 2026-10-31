#!/usr/bin/env python3

"""

A positive integer can be diluted by inserting a 0 between two bits in its binary expansion. This means that an n-bit number has n-1 dilutions, which are not necessarily all distinct.

For example, for 12 (or 1100 in binary), the dilutions are

11000 = 24
   ^

11000 = 24
  ^

10100 = 20
 ^
In this challenge, we're going to be taking the sum of all the dilutions, exclusive of the original number. For 12, taking the sum of 24, 24, 20 results in 68, so 68 should be the output for 12.

Challenge
Given a positive integer n > 1 as input, output/return the diluted sum as explained above.

Examples
in    out
---   ---
2       4
3       5
7      24
12     68
333  5128
512  9216

Rules
The input and output can be assumed to fit in your language's native integer type.
The input and output can be given in any convenient format.
Either a full program or a function are acceptable. If a function, you can return the output rather than printing it.
Standard loopholes are forbidden.
This is code-golf so all usual golfing rules apply, and the shortest code (in bytes) wins.

"""

from functools import lru_cache

"""

@ovs

How?
Each call of the recursive function calculates a single dilution. The position of the inserted 0 is log2(i). The function recurses until i gets bigger than n and the insertion would be on the left of the number. If i>n, n/i evaluates to 0, which is a falsy value in Python.

n*2 shifts the entire number one binary digit left, n%i or n % 2**(position of insertion) calculates the value of the part that should not be shifted left. This value gets subtracted from the shifted number.

Example (n=7)
call       n/i          bin(n)  n*2     n%i   dilution       return value

f(7, i=2)  3 => truthy  0b111   0b1110  0b1   0b1101 = 13    13 + f(7, 2*2) = 13 + 11 = 24
f(7, i=4)  1 => truthy  0b111   0b1110  0b11  0b1011 = 11    11 + f(7, 4*2) = 11 + 0 = 11
f(7, i=8)  0 => falsy                                        0

"""

@lru_cache(maxsize=None)
def dilute(n, i=2):
    if n//i == 0:
        return 0
    return n*2 - n%i + dilute(n, i*2)

def main():
    assert(dilute(2) == 4)
    assert(dilute(3) == 5)
    assert(dilute(7) == 24)
    assert(dilute(12) == 68)
    assert(dilute(333) == 5128)
    assert(dilute(512) == 9216)

main()

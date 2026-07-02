#!/usr/bin/env python3

"""

Given a list of positive integers I=I1,I2,I3,...,In and a base b>1 return their "carry-less sum", i.e. represent I in base b and sum digit-by-digit discarding carry.

Worked example:

I = 13, 2, 9; b = 3
In base 3:

   111
 +   2
 + 100
 -----
 = 210

and back to base 10:

desired output: 21
More test cases:

I=[1000, 576, 23, 1, 141], b=12 => 1573

I=[1000, 576, 23, 1, 141], b=2 => 307

I=[1, 2, 3, 4, 5, 6, 7, 8, 9, 10], b=4 => 11

I=[1, 2, 3, 5, 8, 13, 21, 34, 55], b=5 => 77

I=[900, 100], b=10 => 0

This is code-golf shortest function or program per language wins.

Standard rules and loopholes apply.

"""

def carryless(I, b):
    s = sum(I)
    if s == 0 or b == 0:
        return 0
    return s%b + b*carryless([x//b for x in I], b)

def main():
    assert(carryless([13, 2, 9], 3) == 21)
    assert(carryless([1000, 576, 23, 1, 141], 12) == 1573)
    assert(carryless([1000, 576, 23, 1, 141], 2) == 307)
    assert(carryless([1, 2, 3, 4, 5, 6, 7, 8, 9, 10], 4) == 11)
    assert(carryless([1, 2, 3, 5, 8, 13, 21, 34, 55], 5) == 77)
    assert(carryless([900, 100], 10) == 0)

main()

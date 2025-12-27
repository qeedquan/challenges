#!/usr/bin/env python3

"""

Without using strings (except when necessary, such as with input or output) calculate the nth digit, from the left, of an integer (in base 10).

Input will be given in this format:

726433 5
Output should be:

3
as that is the fifth digit of "726433".

Input will not contain leading zeros, e.g. "00223".

Test cases / further examples:

9 1  ->  9
0 1  ->  0
444494 5  ->  9
800 2  ->  0
This is code golf; least amount of characters wins, but any built in functions such as "nthDigit(x,n)" are not acceptable.

Here's some pseudo-code to get you started:

x = number
n = index of the digit
digits = floor[log10[x]] + 1
dropRight = floor[x / 10^(digits - n)]
dropLeft = (dropRight / 10 - floor[dropRight / 10]) * 10
nthDigit = dropLeft
As you can see I'm new to code golf, and though I think it's a bit unfair that I ask a question before I've even answered one, I would really like to see what kind of responses this generates. :)

Edit: I was hoping for mathematical answers, so I cannot really accept answers that rely on converting strings to arrays or being able to access numbers as a list of digits.

We have a winner
Written in "dc", 12 bytes. By DigitalTrauma.

"""

from math import *

def nth(x, n):
    if x < 1:
        return 0

    d = floor(log10(x)) + 1
    r = floor(x / 10**(d - n))
    l = 10 * (r/10 - floor(r/10))
    l = round(l)
    return int(l)

def main():
    assert(nth(726433, 5) == 3)
    assert(nth(9, 1) == 9)
    assert(nth(0, 1) == 0)
    assert(nth(444494, 5) == 9)
    assert(nth(800, 2) == 0)

main()


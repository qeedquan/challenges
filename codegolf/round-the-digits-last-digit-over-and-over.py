#!/usr/bin/env python3

"""

Challenge:
Given two inputs, x and y, round x to one less significant figure, then repeat until it has y number of unrounded digits left. (the decimal point does not count as a digit)

Input & Output
Input can be a combination of strings and integers, e.g. you can have the input as a string and the output as an int, or vice versa.
The input number will never have 15 digits total, and the y will never be greater than the input number's length and will always be greater than 0.
Example:

x = 32.64712, y = 3
    32.64712 -> 32.6471 -> 32.647 -> 32.65 -> 32.7  (Three unrounded digits left)

x = 87525, y = 2
    87525 -> 87530 -> 87500 -> 88000 (Two unrounded digits left)

x = 454, y = 3
    454 -> 454 (Three unrounded digits left)
(steps shown just to clarify, you only need to output the last value.)

Rules
Trailing 0's are allowed
5's round up
Standard loopholes apply
This is code-golf, so you should strive for the shortest answer.

"""

from functools import reduce

def rld(x, y):
    return reduce(round, range(15, y - len(str(int(x))) - 1, -1), x)

def main():
    print(rld(32.64712, 3))
    print(rld(87525, 2))
    print(rld(454, 3))

main()


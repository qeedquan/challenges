#!/usr/bin/env python3

"""

Challenge
Given an integer greater or equal to 4, n, print a rounded rectangle of as close as possible (with a gap of 1) sides and a perimeter of n characters.

Rules
n is always 4 or greater, because otherwise the output wouldn't be a square
The characters for the perimeter can be any non-whitespace character
The rectangle should have equal sides when possible
When not possible, the rectangle can be up to one character taller or wider than its other side
The rectangle should have one whitespace character in each corner
The rectangle can only ever have a gap of 1 (excluding corners) along the entire perimeter
The gap can be on any side and any position along the perimeter
Rules
Least amount of bytes wins!

Examples
Input: 4
Output:
 o
o o
 o

Input: 5
Output:
 oo
o  o
 o

Input: 8
Output:
 oo
o  o
o  o
 oo

Input: 21
Output:
 oooooo
o      o
o      o
o      o
o      o
o      o
 ooooo

Here is the python3 code I used to generate the above examples:

import math

ch = 'o'

def print_rect(p):
    side_length = math.ceil(p / 4)
    height = side_length
    remainder = p - side_length * 3
    p = side_length + 2

    if side_length - remainder >= 2 or not remainder:
        remainder += 2
        height -= 1

    lines = [(ch * side_length).center(p)]
    for i in range(height):
        lines.append(ch + ch.rjust(side_length + 1))
    lines.append((ch * remainder).center(p))

    print('Output:')
    for line in lines:
        print(line)

print_rect(int(input('Input: ')))

"""

import math

def rounded_rectangle(p):
    n = p
    ch = 'o'
    side_length = math.ceil(p / 4)
    height = side_length
    remainder = p - side_length * 3
    p = side_length + 2

    if side_length - remainder >= 2 or not remainder:
        remainder += 2
        height -= 1

    lines = [(ch * side_length).center(p)]
    for i in range(height):
        lines.append(ch + ch.rjust(side_length + 1))
    lines.append((ch * remainder).center(p))

    print('n=%d' % (n))
    for line in lines:
        print(line)
    print()

def main():
    rounded_rectangle(4)
    rounded_rectangle(5)
    rounded_rectangle(8)
    rounded_rectangle(21)

main()

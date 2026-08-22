#!/usr/bin/env python3

"""

Consecutive natural numbers from a to b are written together in order, without spaces, to form a large number.
This large number is divisible by the natural number c with no remainder.
Given a and c, find the smallest possible value of b.

Input
The input contains two integers a and c (a,c<10000, a≤b).

Output
Print the smallest integer b.

Examples
Input #1
11 3

Answer #1
13

"""

def solve(a, c):
    s = ""
    b = a
    while True:
        s += str(b)
        if int(s)%c == 0:
            return b
        b += 1

def main():
    assert(solve(11, 3) == 13)

main()

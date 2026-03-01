#!/usr/bin/env python3

"""

This is a CMC (chat mini challenge) that I posted in our chatroom, The Ninteenth Byte, a bit ago.

The Challenge
Given a positive integer x, depending on the last 2 bits of x, do the following:

x & 3 == 0: 0
x & 3 == 1: x + x
x & 3 == 2: x * x
x & 3 == 3: x ^ x (exponentiation)
Input/Output
Single Integer -> Single Integer  
A trailing newline is permitted in the output. No other whitespace is permitted.

Testcases
input       output
    1            2
    2            4
    3           27
    4            0
    5           10
    6           36
    7       823543
    8            0
    9           18
   10          100
   11 285311670611
   12            0
This is a code-golf challenge, so the shortest code wins!

"""

def mpte(n):
    op = n & 3
    if op == 0:
        return 0
    if op == 1:
        return n + n
    if op == 2:
        return n * n
    return n**n

def main():
    assert(mpte(1) == 2)
    assert(mpte(2) == 4)
    assert(mpte(3) == 27)
    assert(mpte(4) == 0)
    assert(mpte(5) == 10)
    assert(mpte(6) == 36)
    assert(mpte(7) == 823543)
    assert(mpte(8) == 0)
    assert(mpte(9) == 18)
    assert(mpte(10) == 100)
    assert(mpte(11) == 285311670611)
    assert(mpte(12) == 0)

main()

#!/usr/bin/env python3

"""

Background
An n-bit Gray code is an ordering of 2n binary sequences so that adjacent sequences always differ by exactly one bit.

A Beckett-Gray code is a special kind of Gray code. In addition to being a Gray code, it has the following characteristics:

It is cyclic: the last bit pattern has one bit difference with the first pattern. (Your input is guaranteed to be cyclic)
The first pattern is all zeros. (Your input is guaranteed to start with 0)
Whenever a bit turns from 1 to 0, that bit is the one which has been 1 for the longest time (consecutively). (You need to verify this)
It is known that a Beckett-Gray code exists for  n=2,5,6,7,8, but does not exist for n=3 and 4.
It is not known if any such code exists for  n≥9, and no constructive methods to build such a code are known.

One example for n=5 is as follows (copied from this paper, 1-0 transition marked):

00000, 00001, 00011, 00010, 00110, 00111, 00101, 01101,
                         ^                   ^
01001, 01000, 01010, 01011, 11011, 10011, 10111, 10101,
  ^        ^                        ^               ^
10100, 00100, 01100, 11100, 11000, 11010, 10010, 10110,
    ^  ^                      ^            ^
11110, 01110, 01111, 11111, 11101, 11001, 10001, 10000
       ^                       ^     ^     ^         ^
Task
Given a cyclic Gray code starting with an all-zero pattern, determine if it is a Beckett-Gray code.

You may take input as a sequence of boolean arrays (possibly transposed), a sequence of strings, or a sequence of equivalent integers.
Also, you may optionally take the value of n as the second input.

For output, you can choose to

output truthy/falsy using your language's convention (swapping is allowed), or
use two distinct values to represent true (affirmative) or false (negative) respectively.
Standard code-golf rules apply. Shortest code in bytes wins.

Test cases
Each test case is separated with an empty line.

Truthy (Beckett)
0, 1

00, 01, 11, 10

00, 10, 11, 01

00000, 00001, 00011, 00010, 00110, 00111, 00101, 01101,
01001, 01000, 01010, 01011, 11011, 10011, 10111, 10101,
10100, 00100, 01100, 11100, 11000, 11010, 10010, 10110,
11110, 01110, 01111, 11111, 11101, 11001, 10001, 10000

00000, 01000, 01001, 00001, 00011, 01011, 01010, 11010,
11000, 10000, 10001, 11001, 11101, 01101, 01111, 01110,
00110, 00010, 10010, 10110, 10100, 10101, 00101, 00111,
10111, 10011, 11011, 11111, 11110, 11100, 01100, 00100
Falsy (Not Beckett)
000, 001, 011, 010, 110, 111, 101, 100

0000, 1000, 1100, 1110, 1111, 1101, 0101, 0001,
1001, 1011, 1010, 0010, 0011, 0111, 0110, 0100

00000, 00001, 00011, 00010, 00110, 00111, 00101, 00100,
01100, 01101, 01111, 01110, 01010, 01011, 01001, 01000,
11000, 11001, 11011, 11010, 11110, 11111, 11101, 11100,
10100, 10101, 10111, 10110, 10010, 10011, 10001, 10000

"""

from collections import deque

def beckett_code(values):
    result = 1
    pending = deque()
    for current, following in zip(values, values[1:]):
        difference = current ^ following
        if current < following:
            pending.append(difference)
        elif not pending or pending.popleft() != difference:
            result = 0
    return result

def main():
    tests = (
      ["0", "1"],
      ["00", "01", "11", "10"],
      ["00", "10", "11", "01"],
      ["00000", "00001", "00011", "00010", "00110", "00111", "00101", "01101", "01001", "01000", "01010", "01011", "11011", "10011", "10111", "10101", "10100", "00100", "01100", "11100", "11000", "11010", "10010", "10110", "11110", "01110", "01111", "11111", "11101", "11001", "10001", "10000"],
      ["00000", "01000", "01001", "00001", "00011", "01011", "01010", "11010", "11000", "10000", "10001", "11001", "11101", "01101", "01111", "01110", "00110", "00010", "10010", "10110", "10100", "10101", "00101", "00111", "10111", "10011", "11011", "11111", "11110", "11100", "01100", "00100"],
      ["000", "001", "011", "010", "110", "111", "101", "100"],
      ["0000", "1000", "1100", "1110", "1111", "1101", "0101", "0001", "1001", "1011", "1010", "0010", "0011", "0111", "0110", "0100"],
      ["00000", "00001", "00011", "00010", "00110", "00111", "00101", "00100", "01100", "01101", "01111", "01110", "01010", "01011", "01001", "01000", "11000", "11001", "11011", "11010", "11110", "11111", "11101", "11100", "10100", "10101", "10111", "10110", "10010", "10011", "10001", "10000"],
    )
    expecteds = (1, 1, 1, 1, 1, 0, 0, 0)
    for test, expected in zip(tests, expecteds):
        values = [int(element, 2) for element in test]
        assert(beckett_code(values) == expected)

main()

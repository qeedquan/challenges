#!/usr/bin/env python3

"""

Background
There's a common riddle that goes something like this:

A snail is at the bottom of a 30 foot well. Every day the snail is able to climb up 3 feet. At night when they sleep, they slide back down 2 feet. How many days does it take for the snail to get out of the well?

The intuitive answer is

30 days, because the snail climbs at 1 foot per day for 30 days to reach the top,

but actually the answer is

28 days, because once the snail is 27 feet in the air (after 27 days), they will simply climb the remaining 3 feet to the top on the 28th day.

Challenge
This challenge generalizes this riddle. Given three positive integers as input, representing the total height, the climb height, and the fall height, return the number of days it will take to climb out of the well.

If the snail cannot climb out of the well, you may return 0, return a falsy value, or throw an exception. You may also write code that will halt if and only if a solution exists.

If you wish, you may take the fall height as a negative integer.

Test Cases
(30,  3,  2) -> 28
(84, 17, 15) -> 35
(79, 15,  9) -> 12
(29, 17,  4) -> 2
(13, 18,  8) -> 1
( 5,  5, 10) -> 1
( 7,  7,  7) -> 1
(69,  3,  8) -> None
(81, 14, 14) -> None

Scoring
This is code-golf, so the shortest answer in each language wins.

"""

from math import floor

def days(h, c, f):
    if floor(c/h) > 0:
        return 1
    if floor(f/c) == 1:
        return 0
    return max(1 - floor((h-c)/(f-c)), 0)

def main():
    assert(days(30, 3, 2) == 28)
    assert(days(84, 17, 15) == 35)
    assert(days(79, 15, 9) == 12)
    assert(days(29, 17, 4) == 2)
    assert(days(13, 18, 8) == 1)
    assert(days(5, 5, 10) == 1)
    assert(days(7, 7, 7) == 1)
    assert(days(69, 3, 8) == 0)
    assert(days(81, 14, 14) == 0)

main()

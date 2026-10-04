#!/usr/bin/env python3

"""

Credit to Geobits in TNB for the idea

A post without sufficient detail recently posited an interesting game:

2 children sit in front of an array of candy. Each piece of candy is numbered 1 to x, with x being the total amount of candy present. There is exactly 1 occurrence of each number.

The goal of the game is for the children to eat candy and multiply the values of the candy they have eaten to arrive at a final score, with the higher score winning.

However the original post missed key information, such as how candy is selected, so the kids in our story decided that the older kid gets to go first, and can eat up to half the candy, however once he announces the end of his turn, he can't change his mind.

One of the kids in this game doesn't like candy, so he wants to eat as little as possible, and he once watched his dad write some code once, and figures he can use the skills gained from that to work out how much candy he needs to eat to ensure victory, whilst still eating as little as possible.

The Challenge
Given the total number of candy x, your program or function should output the smallest amount of candy he has to eat to ensure victory, n, even if his opponent eats all the remaining candy.

Naturally bigger numbers make bigger numbers, so whatever amount you'll give him, he'll eat the n largest numbers.

The Rules
x will always be a positive integer in the range 0 < x! <= l where l is the upper limit of your language's number handling capabilities
It is guaranteed that the kid will always eat the n largest numbers, for example for x = 5 and n = 2, he will eat 4 and 5
Test cases
x = 1
n = 1
(1 > 0)

x = 2
n = 1
(2 > 1)

x = 4
n = 2
(3 * 4 == 12 > 1 * 2 == 2)

x = 5
n = 2
(4 * 5 == 20 > 1 * 2 * 3 == 6)

x = 100
n = 42
(product([59..100]) > product([1..58]))

x = 500
n = 220
(product([281..500]) > product([1..280]))

Scoring
Unfortunately, our brave contestant has nothing to write his code with, so he has to arrange the pieces of candy into the characters of the code, as a result, your code needs to be as small as possible, smallest code in bytes wins!

"""

from math import *

"""

@nedla2004

Relies on the fact that for eating n candies to still win and the total number of candies being x, x!/(x−n)! > (x−n)! must be true, which means x! > (x−n)!^2.

"""
def candies(x, n=1):
    if x < 1:
        return 0
    if x < 2:
        return 1
    if factorial(x) <= factorial(x - n)**2:
        return candies(x, n + 1)
    return n

def main():
    assert(candies(0) == 0)
    assert(candies(1) == 1)
    assert(candies(2) == 1)
    assert(candies(3) == 1)
    assert(candies(4) == 2)
    assert(candies(5) == 2)
    assert(candies(6) == 2)
    assert(candies(7) == 3)
    assert(candies(8) == 3)
    assert(candies(9) == 4)
    assert(candies(10) == 4)
    assert(candies(11) == 4)
    assert(candies(12) == 5)
    assert(candies(13) == 5)
    assert(candies(14) == 6)
    assert(candies(15) == 6)
    assert(candies(16) == 6)
    assert(candies(17) == 7)
    assert(candies(18) == 7)
    assert(candies(19) == 8)
    assert(candies(20) == 8)
    assert(candies(100) == 42)
    assert(candies(311) == 135)
    assert(candies(500) == 220)

main()


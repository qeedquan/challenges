#!/usr/bin/env python3

"""

Introduction
Let's start by arranging all fractions from 0 to 1 in order of lowest denominator, then lowest numerator:

1/2, 1/3, 2/3, 1/4, 3/4, 1/5, 2/5, 3/5, 4/5, 1/6, 5/6, 1/7...

Note that duplicates aren't counted, so I haven't listed 2/4, 2/6, 3/6, or 4/6, since they already appeared in their simplified forms (1/2, 1/3, and 2/3).

Your task is now simple: given a positive integer nas a command line argument, print to standard output the nth fraction in the list. Thus, an input of 5 should yield an output of 3/4 (not 0.75).

Bowlers
Your goal is to solve this in the longest program possible. Your score is the number of characters.

Golfers
Your goal is to take existing answers, and golf them. When golfing those answers, remove one or more characters from the code, and optionally rearrange the remaining characters, in such a way that the resulting code is still a valid solution in the same language. Your score is the product of all the reductions. (So if you remove 10 characters from one answer, and 15 from another, your score is 150.)

Rules
A valid program must have at least three unique characters.
Only ASCII characters may be used.
If your program's size is reduced, your score is reduced accordingly.
When golfing a program...
Edit the code in the text of the answer
Change the character count listed
Leave the following comment: **Removed X characters (from Y to Z)** (in bold)
You may not golf a valid program into an invalid one.
The golfed program must work in some version of the language listed. So if the original answer is marked as Python, and the code only works in Python 2, you may golf it to a program that only works in Python 3.
Therefore, it is recommended (but not required) that you be specific in titling your answer, mentioning the version and/or compiler used.
If you already golfed an answer, you may golf it again.
If you golf the same answer multiple times, your score for that answer is the sum of your reductions.
For example, if you reduce 10 characters from a program, and later remove another 15, and also golf 7 characters from another answer, your total score is (10+15)*7=175.
This applies regardless of whether someone else golfed the program in between your golfings.
You may golf your own answer, but you do not receive any points for doing so.

"""

from math import *

# Based on @Soham Chowdhury solution
def fraction(n):
    c = 0
    for i in range(n + 10):
        for j in range(1, i):
            if gcd(j, i) == 1:
                c += 1
            if c == n:
                return "%d/%d" % (j, i)
    return "0/1"

def main():
    tab = ["1/2", "1/3", "2/3", "1/4", "3/4", "1/5", "2/5", "3/5", "4/5", "1/6", "5/6", "1/7"]

    for i in range(len(tab)):
        assert(fraction(i + 1) == tab[i])

main()

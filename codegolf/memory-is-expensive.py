#!/usr/bin/env python3

"""

You are a robot. You are stranded in a small cage with weird humans wearing weird suits looking at you. Your solar panel is malfunctioning, and your energy is running out. On the wall there is a riddle, and if you answer correctly the humans will grant you access to an energy source (yay!). However your RAM unit is leaking power, and the more you use it, the more energy will be lost.

For each byte you access, you spend 1 energy unit (a bit costs 1/8 energy).

The program that uses the least energy wins.

Arrays cost the sum of all their variables. Strings and other non-fixed-length variables/arrays are prohibited, as your bot will be unable to calculate how much energy it spent. (Recursion is prohibited too!)

The riddle is weird, it changes after a while, so your bot must not hardcode the answer.

The riddle is a mathematical challenge:

We shall input you with 3 variables, and they are free, but you shall not change them.

For these 3 inputs, a, b and c, thou shalt calculate an integer p equivalent to floor(pi * 10^(c-1)), then you shall calculate x = a!/b!. Then you shall add to x the integer p. If and only if c is greater than x, you shall yell Pi!!!!

a, b and c are integers smaller than the number 13.

Example: for a = 5, b = 4, and c = 3, calculate 5!/4! + 314. as x = 5, and c = 3, don't yell Pi!!!!

Once finished calculating, your bot should output the answer. The input can be either in form of calling a function or the user typing a number when prompted.

If 2 bots have the same energy spending, the shortest code wins.

Also, the energy cost is for the worst case (that's why I said a, b and c are smaller than 13). (Extra clarification: the language overheads don't count, unless you abuse them to store data.)

"""

from math import *

def calculate(a, b, c):
    p = floor(pi * 10**(c - 1))
    x = factorial(a)/factorial(b) + p
    if c > p:
        print("Pi!!!!")

def main():
    calculate(5, 4, 3)

main()

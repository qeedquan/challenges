#!/usr/bin/env python3

"""

Challenge
I'm under attack by the larcenous Midnight Crew and I need to summon the Catenative Doomsday Dice Cascader in order to defend myself. Since I'm low on space, I need the code to be as short as possible.

The algorithm for the Catenative Doomsday Dice Cascader is as follows:

First, the six sided die in the Prime Bubble is rolled, and the result will determine how many iterations of the next step take place.

Start with a six sided die. For as many times as the roll of the Prime Bubble die, multiply the number of sides on the next die by the result of the roll of the current die. For example, if on your first roll of the six-sided die your roll is 2, then your next die will have 6*2 = 12 sides.

Your goal is to write a function or program that takes no input and outputs the final result of the last die rolled. Since this is code-golf, the lowest byte count in each language wins!

Examples
Example #1 (Taken directly from the link above):

The Prime Bubble rolls a 6, meaning that the Cascader will iterate six times

#1: We always start with a 6 sided die, and it rolls a 2, so the next die has 6x2=12 sides
#2: The 12 sided die rolls an 8, meaning that the third die has 12x8=96 sides
#3: The 96 sided die rolls a 35, meaning that die 4 has 96x35=3360 sides
#4: The 3360 sided die rolls a 2922, so die 5 has 3360x2922 = 9,817,920 sides
#5: The 9.8 million sided die rolls a 5,101,894, so the final die has 50,089,987,140,480 sides
#6: The 50 trillion sided die rolls a one. Hooray.
Since the last die rolled gave a 1, your function or program should output 1.
Example #2

The Prime Bubble rolls a 2, meaning that the Cascader will iterate twice.

#1: We always start with a 6 sided die, and it rolls a 4, so the next die has 6x4 = 24 sides
#2: The 24 sided die rolls a 14

Since the last die rolled gave a 14, your function or program should output 14.

"""

from random import *

def gen(n):
    v = n
    p = 0
    for _ in range(randint(1, n)):
        p = randint(1, v)
        v *= p
    return p

def main():
    for _ in range(10):
        print(gen(6))

main()

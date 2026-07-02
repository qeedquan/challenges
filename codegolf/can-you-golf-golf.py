#!/usr/bin/env python3

"""

You are required to generate a random 18-hole golf course.

Example output:

[3 4 3 5 5 4 4 4 5 3 3 4 4 3 4 5 5 4]
Rules:

Your program must output a list of hole lengths for exactly 18 holes
Each hole must have a length of 3, 4 or 5
The hole lengths must add up to 72 for the entire course
Your program must be able to produce every possible hole configuration with some non-zero-probability (the probabilities of each configuration need not be equal, but feel free to claim extra kudos if this is the case)

"""

from numpy.random import *

def gen():
    x = []
    while sum(x) != 72:
        x = randint(3, 6, 18)
    return x

def main():
    print(gen())

main()

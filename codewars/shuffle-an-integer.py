#!/usr/bin/env python3

r"""
Task
Write a function that returns a "shuffled" version of an integer...

Shuffle?
             (    puzzle!    )

...with your method deduced from the rules, examples, and tests.

Input
A non-zero positive integer n.

Output
A different non-negative integer,
        being a fair random choice of one of the possible shufflings of the given input n
                (if any exist),
        otherwise 0.

Singularity
An integer cannot shuffle into itself.

Duality
Some pairs of integers can shuffle from one into the other interchangeably.
Other pairs can only shuffle from one of the numbers into the other number.

Multiplicity
integers can generally be shuffled in multiple ways
possibly an integer could be shuffled only one way
for shuffling some integers there are no ways at all

Functionality
As opposed to simply returning any valid shuffled version of an integer,
the function must evenly return all possible outputs for the given input
with approximate equal frequency at a minimum confidence of 97.5%.

Examples
1 cannot be shuffled
2 can only be shuffled into 1
3 cannot be shuffled
4 can be shuffled into 1 or 2
5 can be shuffled into 3 or 6
6 can be shuffled into 3 or 5
7 cannot be shuffled
8 can be shuffled into 1, 2, or 4
9 can be shuffled into 3, 5, 6, 10, or 12

"""

import math
import random

def shuffint(n):
    k = n.bit_length()          
    ones = n.bit_count()       

    total = math.comb(k, ones)
    if total <= 1:
        return 0

    while True:
        positions = random.sample(range(k), ones)
        m = 0
        for p in positions:
            m |= (1 << p)
        if m != n:     
            return m

for i in range(1, 10):
    print(shuffint(i))


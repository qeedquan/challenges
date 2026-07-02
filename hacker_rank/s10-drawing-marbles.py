#!/usr/bin/env python3

"""

Task
A bag contains 3 red marbles and 4 blue marbles.
Then, 2 marbles are drawn from the bag, at random, without replacement.
If the first marble drawn is red, what is the probability that the second marble is blue?

"""

from itertools import permutations
from math import gcd

"""

A bag contains 3 red marbles and 4 blue marbles
After drawing a red marble, the bag has now 2 red and 4 blue marbles (total of 6 marbles)
Therefore, the probability of getting a blue marble is 4/6 = 2/3

"""

def solve(reds, blues):
    R = ['R'] * reds
    B = ['B'] * blues

    x, y = 0, 0
    for m in permutations(R + B, 2):
        if m[0] == 'R':
            if m[1] == 'B':
                x += 1
            y += 1
    
    l = gcd(x, y)
    return (x//l, y//l)

def main():
    print(solve(3, 4))

main()

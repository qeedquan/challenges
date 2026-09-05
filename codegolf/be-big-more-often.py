#!/usr/bin/env python3

"""

You are a manager at a large number factory. You want to show everyone your business is doing well, by showing randomly chosen samples. Unfortunately, your business is not doing that well. But luckily, you have a bit of ingenuity...

Write a program or function that when given an array of unique, positive numbers, it returns a random number from the array, with bigger numbers having a higher probability of being chosen (an>am⟹P(an)>P(am)), no two numbers being chosen with the same probability (P(an)≠P(am)), and all numbers having a non-zero chance of being chosen (P(an)≠0). Anyways, this is code-golf, so shortest code wins!

"""

from random import *

# @MTN solution
def get(a):
    return choices(a, a)

def main():
    for i in range(10):
        print(get([1, 2, 3, 4, 5]))

main()

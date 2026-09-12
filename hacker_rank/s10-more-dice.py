#!/usr/bin/env python3

"""

Objective
In this challenge, we practice calculating probability. We recommend you review the previous challenge's Tutorial before attempting this problem.

Task
In a single toss of 2 fair (evenly-weighted) six-sided dice, find the probability that the values rolled by each die will be different and the two dice have a sum of 6.

"""

from math import *

def solve(s):
    n = 0
    d = 6
    for i in range(1, d + 1):
        for j in range(1, d + 1):
            if i != j and i + j == s:
                n += 1
    l = gcd(n, d*d)
    return (n//l, (d*d)//l)

def main():
    print(solve(6))

main()

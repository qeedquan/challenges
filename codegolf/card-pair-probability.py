#!/usr/bin/env python3

r"""

Given a deck consisting of N copies of cards with integer values [1,M] for a total of N*M cards, compute the probability that a card with the value of 1 is adjacent to a card with the value of 2.

Your solution may be exact or approximated, and it does not need to be the same for every run given the same inputs. The given answer should be within +/-5% of the true solution (barring really rare chances the RNG is not in your favor). Your program should give the answer in a reasonable amount of time (say, less than 10 minutes on whatever hardware you have). You may assume that M and N are reasonable small and error checking is not required.

The deck is not cyclical, so if the first card is a 1 and the last card is a 2, this does not meet the adjacency requirements.

As a test case, for N=4 and M=13 (a standard 52-card deck) the expected solution is ~48.6%.

Here is an example un-golfed implementation in Python+NumPy using random shuffles:

from __future__ import division
from numpy import *

def adjacent(N, M):
    deck = array([i for i in range(1, M+1)]*N)
    trials = 100000
    count = 0
    for i in range(trials):
        random.shuffle(deck)
        ores = (deck == 1)
        tres = (deck == 2)
        if(any(logical_and(ores[1:], tres[:-1])) or
           any(logical_and(ores[:-1], tres[1:]))):
            count += 1
    return count/trials
The output may be in any form you find convenient (function return value, terminal output, file, etc.), and input may be in any form you find convenient (function parameter, terminal input, command line arg, etc.)

Standard loop-holes apply.

This is code golf, the shortest code (in bytes) wins.

"""

from numpy import *

def adjacent(N, M):
    deck = array([i for i in range(1, M + 1)] * N)
    trials = 100000
    count = 0
    for i in range(trials):
        random.shuffle(deck)
        ones = (deck == 1)
        twos = (deck == 2)
        if any(logical_and(ones[1:], twos[:-1])) or any(logical_and(ones[:-1], twos[1:])):
            count += 1
    return count/trials

def main():
    print(adjacent(4, 13))

main()

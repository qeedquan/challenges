#!/usr/bin/env python3

"""

Your task is to build a piece of code that generates an aperiodic sequence of integers, either by outputting one every time it iterates, or by taking an integer n and returning the nth number in that sequence.

Now, the sequence 1, 2, 3, 4, 5, 6, ... is itself aperiodic, so I'm going to introduce a few limitations to the definition of "aperiodic" used in this problem to weed out the trivial cases:

The sequence must not be periodic modulo any integer m > 1. So a sequence like the powers of 2 would repeat 2, 4, 8, 6 all the time modulo 10, and therefore not count. (It would also repeat 0 modulo 2.)

The sequence must not become periodic after a certain number of operations - e.g. 1 2 4 8 6 2 4 8 6 ... is still considered periodic even though 1 never appears again.

The generation code must only use integers. So a piece of code that calculated the nth digit of pi (without calculating it in some integer form first) would not be acceptable.

Now, obviously every sequence performed with limited computer memory will eventually either be periodic or run out of memory, but if you can prove that your function, given infinite memory and time, will never loop back to a previous state, then it is acceptable.

The shortest code that does the above wins.

"""

from sympy import *

# https://oeis.org/A001222
def main():
    tab = [0, 1, 1, 2, 1, 2, 1, 3, 2, 2, 1, 3, 1, 2, 2, 4, 1, 3, 1, 3, 2, 2, 1, 4, 2, 2, 3, 3, 1, 3, 1, 5, 2, 2, 2, 4, 1, 2, 2, 4, 1, 3, 1, 3, 3, 2, 1, 5, 2, 3, 2, 3, 1, 4, 2, 4, 2, 2, 1, 4, 1, 2, 3, 6, 2, 3, 1, 3, 2, 3, 1, 5, 1, 2, 3, 3, 2, 3, 1, 5, 4, 2, 1, 4, 2, 2, 2, 4, 1, 4, 2, 3, 2, 2, 2, 6, 1, 3, 3, 4, 1, 3, 1, 4, 3, 2, 1, 5, 1, 3, 2]

    for i in range(len(tab)):
        assert(primeomega(i + 1) == tab[i])

main()

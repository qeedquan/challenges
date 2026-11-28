#!/usr/bin/env python3

"""

Output an infinite sequence of positive integers, such that, for each element in the sequence, all positive integers that have not yet been output have a positive probability of being chosen, and no value is repeated.

For example, if the first integer is 3, then 3 may not be output again, but all other positive integers have a positive probability of being chosen for the second integer.

Acceptable output methods
Writing to STDOUT, with a consistent, unambiguous separator between integers (such as a newline), with output prior to termination of the program
A named or unnamed function which returns an infinite iterable (such as a Python generator)
A named or unnamed function which outputs the sequence one integer at a time each time it is called within a single execution of the program
A named or unnamed function or program which outputs the next integer in the sequence when called with the previous integer(s) as its sole argument(s) (the first call may either take no arguments or take a seed argument, which may be included in the arguments to later calls)
Rules
There will be no input except an optional seed value, which will be an infinite sequence of random bits.
Submissions must be capable of producing different outputs given different initial conditions (outputting the same sequence every time is not acceptable).
Each element of the sequence must be chosen randomly out of the valid elements (positive integers not already present in the sequence).
You may assume that you have infinite memory available.
You may assume that any real numbers returned by a PRNG are infinite-precision. In other words, if you have a function called rand that returns a random value in [0, 1), you may assume every real value in that interval has a positive probability of being chosen, rather than just the subset of the reals that are representable with floats.
Each integer must be output in a finite amount of time after the last integer (so you can't wait until program termination to output part of the sequence). The first integer must be output in a finite amount of time after the program is started or the function is called.

"""

from random import *

"""

ported from @L3viathan solution

"""

def f(n, x=[], y=1):
    if n < 0:
        return

    while y in x or 0.5 < random():
        y += 1
    yield y
    yield from f(n - 1, x + [y])

def main():
    for v in f(100):
        print(v)

main()

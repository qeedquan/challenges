#!/usr/bin/env python3

"""

Probability to get a 6 on a dice and a head on a coin

1/6 * 1/2 = 1/12

"""

def problem1():
    return 1/6 * 1/2

"""

How many possibilities for 3 letters and 4 numbers?

26^3 * 10^4

"""

def problem2():
    return 26**3 * 10**4

"""

How many possibilities for 3 unique letters and 4 unique numbers?

26*25*24 for the letters
10*9*8*7 for numbers

"""

def problem3():
    return 26*25*24 * 10*9*8*7

"""

How many subsets are possible out of 10 elements

{A}, {B}, {C}, {D}, ... {J}
{AB, {BC}, {AD}, ... {IJ} ...

A way to apply the multiplication principle is to view this as either an element is inside or outside of a subset.
So for 10 elements, 2^10 gives the number of subsets possible

Another way to view this is the powerset of 10 elements is 2^10

"""

def problem4():
    return 2**10

def main():
    print(problem1())
    print(problem2())
    print(problem3())
    print(problem4())

main()

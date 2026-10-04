#!/usr/bin/env python3

from math import *

"""

Distinguishable permutations of n objects then it is equivalent to
nCr = binomial(n, r)

If there are n1, n2, n3, ... nk types then
multinomial(n, n1*n2*n3...nk) = n! / (n1! * n2! * n3! ... * nk!)

"""

"""

Suppose we toss a gold dollar coin 8 times. What is the probability that the sequence of 8 tosses yields 3 heads (H) and 5 tails (T)?

We can think of choosing r=3 positions for the heads (H) out of the n=8 possible tosses.
That would, of course, leave then n-r (8-3=5) positions for the tails (T).
Using the formula for a combination of n objects taken r at a time, there are therefore:

comb(8, 3)

"""

def problem1():
    return comb(8, 3) 

"""

How many ordered arrangements are there of the letters in MISSISSIPPI?

MISSISSIPPI = 11!

Divide by the number of possibilities that we couldn't distinguish so:

11! / (1! * 4! * 4! * 2!)

"""

def problem2():
    return factorial(11) // (factorial(1)*factorial(4)*factorial(4)*factorial(2))

"""

How many ordered arrangements are there of the letters in the word PHILIPPINES?

PHILIPPINES = 11!

P=3!
I=3!
Rest of the letters is 1! so

11! / (3!*3!)

"""

def problem3():
    return factorial(11) // (factorial(3)**2)

"""

Fifteen (15) pigs are available to use in a study to compare three (3) different diets.
Each of the diets (let's say, A, B, C) is to be used on five randomly selected pigs.
In how many ways can the diets be assigned to the pigs?

Pigs = 15!

Number of ways for each diet = 5! so
15! / (5! * 5! * 5!)

"""

def problem4():
    return factorial(15) // factorial(5)**3

def main():
    print(problem1())
    print(problem2())
    print(problem3())
    print(problem4())

main()

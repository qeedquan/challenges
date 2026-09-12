#!/usr/bin/env python3

"""

Permutations is a generalization of the multiplication principle

For a regular permutation, we can view this as permutation of n objects taken n at a time:
nPn = n!

One way to view permutations is that it is sampling without replacement
If there was replacement when we sampled, then it becomes the multiplication principle

For n objects taken r at a time (r <= n), then this becomes:
nPr = n!/(n-r)!

"""

from math import *

"""

How many ways can four people fill executive positions?

4*3*2*1

"""

def problem1():
    return factorial(4)

"""

How many ways can 366 days be ranked?
366!

"""

def problem2():
    return factorial(366)

"""

What is the probability that your birthday will be ranked first in 366 days?

1/366

"""

def problem3():
    return 1/366

"""

How many ways can 7 different books be arranged on a bookshelf?

7!

"""

def problem4():
    return factorial(7)

"""

With 6 names in a bag, randomly select a name. How many ways can the 6 names be assigned to 6 job assignments?
6!

If we select a name and return it to the bag, how many ways can 6 names be assigned to 6 jobs?
6^6

"""

def problem5():
    return (factorial(6), 6**6)

"""

How many ways can 4 people fill 3 chairs?

Use nPr = (4)P(3) = 4!/(4-3)!

"""

def problem6():
    return factorial(4)//factorial(4-3)

"""

An artist has 9 paintings. How many ways can he hang 4 paintings side-by-side on a gallery wall?
nPr = (9)P(4)

"""

def problem7():
    return factorial(9)//factorial(9-4)

def main():
    print(problem1())
    print(problem2())
    print(problem3())
    print(problem4())
    print(problem5())
    print(problem6())
    print(problem7())

main()

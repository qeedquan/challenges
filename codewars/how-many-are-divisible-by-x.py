#!/usr/bin/env python3

"""

How Many are Divisible by x

example
Suppose an integer from 1 through parameter m: 1000 is chosen at random, and the given parameter x: "2 or 9" then you have to find the number of numbers between 1 to 1000 which is/are multiple/divisible by 2 or 9.

task
give two parameters m and x, where m defines the max range starting from 1. You have to return the number of the numbers that can be multiple/divisible by x, where x is a string that consist 2 numbers and "and" or "or" example- "2 or 9"

test cases example:

from 1 to 1000, random chosen number of numbers being multiple of 2 or 9 is 556
how_many(1000, "2 or 9") # should return 556
how_many(1000, "2 and 9") # should return 55
how_many(200, "10 or 10") # should return 20

note

Take care of the performace as it may required in big range numbers

if range is negative then return 0.

"""

from math import lcm

def count(m, a, op, b):
    if m < 1:
        return 0
    l = lcm(a, b)
    if op == "and":
        return m//l
    elif op == "or":
        return m//a + m//b - m//l
    return -1

def main():
    assert(count(1000, 2, "or", 9) == 556)
    assert(count(1000, 2, "and", 9) == 55)
    assert(count(200, 10, "or", 10) == 20)

main()

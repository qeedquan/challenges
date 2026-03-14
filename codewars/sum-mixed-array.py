#!/usr/bin/env python3

"""

Given an array of integers as strings and numbers, return the sum of the array values as if all were numbers.

Return your answer as a number.

"""

def summix(a):
    r = 0
    for x in a:
        r += int(x)
    return r

def main():
    assert(summix([1, 2, 3, "4", "5"]) == 15)

main()

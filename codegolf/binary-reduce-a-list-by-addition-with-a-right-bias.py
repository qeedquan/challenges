#!/usr/bin/env python3

"""

Given a list of 2 or more strictly positive integers, sum the first and last half of the list, with the middle element being counted only in the right half if the list has an odd number of elements

Some examples of the middle element being counted in the right half:

[1, 2, 3, 4]       -> Left: [1, 2];    Right: [3, 4]
[1, 2, 3]          -> Left: [1];       Right: [2, 3]
[1, 2, 3, 4, 5]    -> Left: [1, 2];    Right: [3, 4, 5]
[1, 2, 3, 4, 5, 6] -> Left: [1, 2, 3]; Right: [4, 5, 6]
Test Cases
Input
[1, 9]
[9, 5, 5, 7]
[6, 7, 5, 1, 3, 9, 7, 1, 6]
[2, 8, 10, 9, 9, 3, 7, 8, 9, 8, 6, 1, 2, 9, 8, 3, 8, 9, 5]
[2, 3, 1, 8, 6, 2, 10, 6, 7, 6]
Output
[1, 9]
[14, 12]
[19, 26]
[65, 59]
[20, 31]

Reference Program With Two Output Methods

import functools
import random

def binary_reduce(integers, function):
    left, right = integers[:len(integers) // 2], integers[len(integers) // 2:]
    return [functools.reduce(function, left), functools.reduce(function, right)]

tests = []
for n in range(100):
   n = [random.randint(1, 100) for n in range(random.randint(2, 20))]
   tests.append(n)

# Change the output mode here.
#OUTPUT_MODE = "one-one"
OUTPUT_MODE = "input-output"

if OUTPUT_MODE == "one-one":
    for test in tests:
        print(test, "-->", binary_reduce(test, lambda x, y: x + y))
else:
    for test in tests:
        print(test)

    print()
    for test in tests:
        print(binary_reduce(test, lambda x, y: x + y))


Rules
Input/Output can be Taken/Given in any convenient and reasonable format.
Functions and full programs are both acceptable.

"""

def binary_reduce(a):
    l = sum(a[:len(a)//2])
    r = sum(a) - l
    return [l, r]

def main():
    assert(binary_reduce([1, 9]) == [1, 9])
    assert(binary_reduce([9, 5, 5, 7]) == [14, 12])
    assert(binary_reduce([6, 7, 5, 1, 3, 9, 7, 1, 6]) == [19, 26])
    assert(binary_reduce([2, 8, 10, 9, 9, 3, 7, 8, 9, 8, 6, 1, 2, 9, 8, 3, 8, 9, 5]) == [65, 59])
    assert(binary_reduce([2, 3, 1, 8, 6, 2, 10, 6, 7, 6]) == [20, 31])

main()

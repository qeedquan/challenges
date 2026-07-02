#!/usr/bin/env python3

"""

Task:
Given a list of integers, determine whether the sum of its elements is odd or even.

Give your answer as a string matching "odd" or "even".

If the input array is empty consider it as: [0] (array with a zero).

Examples:
Input: [0]
Output: "even"

Input: [0, 1, 4]
Output: "odd"

Input: [0, -1, -5]
Output: "even"
Have fun!

"""

def odd_or_even(array):
    if sum(array)%2 != 0:
        return "odd"
    return "even"

def main():
    assert(odd_or_even([0]) == "even")
    assert(odd_or_even([0, 1, 4]) == "odd")
    assert(odd_or_even([0, -1, -5]) == "even")

main()

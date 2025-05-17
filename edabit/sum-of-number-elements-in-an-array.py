#!/usr/bin/env python3

"""

Arrays can be mixed with various types. Your task for this challenge is to sum all the number elements in the given array. Create a function that takes an array and returns the sum of all numbers in the array.

Examples
numbersSum([1, 2, "13", "4", "645"]) ➞ 3

numbersSum([true, false, "123", "75"]) ➞ 0

numbersSum([1, 2, 3, 4, 5, true]) ➞ 15

Notes
Check the Resources tab for help.

"""

def numbers_sum(a):
    r = 0
    for x in a:
        if type(x) is int:
            r += x
    return r

def main():
    assert(numbers_sum([1, 2, "13", "4", "645"]) == 3)
    assert(numbers_sum([True, False, "123", "75"]) == 0)
    assert(numbers_sum([1, 2, 3, 4, 5, True]) == 15)
    assert(numbers_sum(["abcd", 1234, False, True, 564, "hii"]) == 1798)
    assert(numbers_sum(["abcd", "abc45", "assssd", True]) == 0)
    assert(numbers_sum([]) == 0)
    assert(numbers_sum(["cghyki", "cd", 12114, 786, True, "me", "bey"]) == 12900)

main()

#!/usr/bin/env python3

"""

Filter the number

Oh, no! The number has been mixed up with the text. Your goal is to retrieve the number from the text, can you return the number back to its original state?
Task

Your task is to return a number from a string.
Details

You will be given a string of numbers and letters mixed up, you have to return all the numbers in that string in the order they occur.

"""

def filter(s):
    r = 0
    for c in s:
        if c.isdigit():
            r = (r * 10) + int(c)
    return r

def main():
    assert(filter("123") == 123)
    assert(filter("a1b2c3") == 123)
    assert(filter("aa1bb2cc3dd") == 123)

main()

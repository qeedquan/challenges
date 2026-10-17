#!/usr/bin/env python3

"""

I want to read two strings on separate lines, each string the same length and containing only 0's and 1's,
and determine if the first is the one's complement of the second.
How succinctly can this be done in Python3? (Sorry to specify the language, but this is for my son who's studying Python)

A list comprehension seems to work but is quite ugly.

if ['0' if x=='1' else '1' for x in input()] == list(input()): print('yep')
Is there a slicker/shorter way to do this?

"""

def solve(a, b):
    if all(x != y for x, y in zip(a, b)):
        print("yep")

def main():
    solve("1001", "0110")
    solve("1001", "0111")

main()

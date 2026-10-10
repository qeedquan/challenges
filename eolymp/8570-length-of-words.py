#!/usr/bin/env python3

"""

Given a text containing a sequence of words. Find the length of each word.

Input
The text contains a sequence of words. The length of each word is no more than 20 characters.

Output
Print the length of each word on a single line.

Examples

Input #1
Programming Principles 1

Answer #1
11 10 1

Input #2
I like C
very
much

Answer #2
1 4 1 4 4

"""

def solve(words):
    for word in words.split():
        print(len(word), end=' ')
    print()

solve("Programming Principles 1")
solve("""
I like C 
very
much
""")

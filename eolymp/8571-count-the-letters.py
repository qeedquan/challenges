#!/usr/bin/env python3

"""

Given a string s and a letter c. Determine how many times the letter c appears in the string s.

Input
The first line contains the string s, with a length not exceeding 100 characters.
The second line contains a lowercase letter c from the Latin alphabet.

Output
Print the number of occurrences of the letter c in the string s.
Upper and lower case letters are considered the same.
For example, the letters ′a′ and ′A′ are considered the same.

Examples

Input #1
Programming Principles 1
p

Answer #1
3

Input #2
This is a cat sitting on a table
t

Answer #2
5

"""

def count(string, letter):
    result = 0
    for symbol in string:
        if symbol.lower() == letter:
            result += 1
    return result

def main():
    assert(count("Programming Principles 1", 'p') == 3)
    assert(count("This is a cat sitting on a table", 't') == 5)

main()


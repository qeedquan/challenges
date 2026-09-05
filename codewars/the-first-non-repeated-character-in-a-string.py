#!/usr/bin/env python3

"""

You need to write a function, that returns the first non-repeated character in the given string.

If all the characters are unique, return the first character of the string.
If there is no unique character, return null in JS or Java, and None in Python.

You can assume, that the input string has always non-zero length.

Example
firstNonRepeated("test") // returns "e"
firstNonRepeated("teeter") // returns "r"
firstNonRepeated("trend") // returns "t" (all the characters are unique)
firstNonRepeated("aabbcc") // returns null (all the characters are repeated)

"""

def first_non_repeated(string):
    seen = {}
    for symbol in string:
        if symbol not in seen:
            seen[symbol] = 0
        seen[symbol] += 1
    
    for symbol in seen:
        if seen[symbol] == 1:
            return symbol
    return None

def main():
    assert(first_non_repeated("test") == 'e')
    assert(first_non_repeated("teeter") == 'r')
    assert(first_non_repeated("trend") == 't')
    assert(first_non_repeated("aabbcc") == None)

main()

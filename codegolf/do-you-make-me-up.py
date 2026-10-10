#!/usr/bin/env python3

"""

Introduction
Every string has an "alphabet", composed of the characters that make it up. For example, the alphabet of abcaabbcc is a,b,c.
There are two operations you can do with alphabets: getting the alphabet of a string, and seeing if another string has a given alphabet.

Challenge
Given two strings, you must write a function that finds the alphabet of the first string, and returns a truthy or falsy value based on whether that alphabet makes up the second string,
ie. if the alphabet of the first string is the same as that of the second.
However, the function should also return a truthy value if the alphabet of the first string is a superset of, or contains, the alphabet of the second.

The two strings will be of variable length. They might be empty. If they are, their alphabets are considered and empty list/set. Any valid unicode string could be an input.
The function must return a truthy or falsy value. Any type of output is OK, as long as, when converted to a boolean in your language (or the equivalent), it is true.

Examples
String 1: "abcdef", String 2: "defbca"
Output: truthy
String 1: "abc", String 2: "abc123"
Output: falsy
String 1: "", String 2: ""
Output: truthy
String 1: "def", String 2: "abcdef"
Output falsy
String 1: "abcdef", String 2: "abc"
Output truthy
String 1: "😀😁😆", String 2: "😁😆😀"
Output: truthy

Rules
This is code-golf, so shortest answer in bytes wins!

"""

def makeup(a, b):
    return set(a) >= set(b)

def main():
    assert(makeup("abcdef", "defbca") == True)
    assert(makeup("abc", "abc123") == False)
    assert(makeup("", "") == True)
    assert(makeup("def", "abcdef") == False)
    assert(makeup("abcdef", "abc") == True)
    assert(makeup("😀😁😆", "😁😆😀") == True)

main()

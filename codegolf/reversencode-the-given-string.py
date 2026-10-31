#!/usr/bin/env python3

"""

Given a string, if it is even, break the string into 2 even parts, then reverse the parts to get the "reversencoded" string.

Example:

onomatopoeia -> tamonoaieopo

If the string is not of even length, then do not change the position of the middle character, and reverse the letters before and after the middle character.

Example:

pizza -> ipzaz

discord -> sidcdro

Limitations: The input will not contain any other characters other than AlphaNumeric characters. i.e. No newlines/whitespaces.

General contest, shortest code in each language will be winning. Good luck!

btw: i made up the word reversencoded, i'm fairly sure such a form of "encryption" doesnt exist

"""

def reverse_encode(s):
    n = len(s)
    s1 = s[:n//2][::-1]
    s2 = ""
    s3 = s[n//2 + n%2:][::-1]
    if n%2 != 0:
        s2 = s[n//2]
    return s1 + s2 + s3

def main():
    assert(reverse_encode("onomatopoeia") == "tamonoaieopo")
    assert(reverse_encode("pizza") == "ipzaz")
    assert(reverse_encode("discord") == "sidcdro")

main()

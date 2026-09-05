#!/usr/bin/env python3

"""

The Challenge

Given two strings containing only lowercase letters and no spaces, the result should be the shorter string, followed by an underscore,
followed by the longer string with the first instance of a character removed for each character it contains that is in the shorter string.

You can assume the strings will always be different lengths.

Test Cases:

sale
salinewater
Result: sale_inwater (only the first 'a' in salinewater is removed)

jostling
juggle
Result: juggle_ostin (juggle is the shorter string)

juggle
juggler
Result: juggle_r (a 'g' is removed for every 'g' in the shorter string)
Rules

This is code-golf, so shortest answer in bytes wins!

"""

def concat(s, t):
    if len(s) > len(t):
        s, t = t, s

    for c in s:
        t = t.replace(c, "", 1)

    return s + "_" + t

def main():
    assert(concat("sale", "salinewater") == "sale_inwater")
    assert(concat("jostling", "juggle") == "juggle_ostin")
    assert(concat("juggle", "juggler") == "juggle_r")

main()

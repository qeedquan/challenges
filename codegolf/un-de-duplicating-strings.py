#!/usr/bin/env python3

"""

Introduction
Let's observe the following string:

AABBCCDDEFFGG
You can see that every letter has been duplicated, except for the letter E. That means that the letter E has been de-duplicated. So, the only thing we need to do here is to reverse that process, which gives us the following un-de-duplicated string:

AABBCCDDEEFFGG
Let's take a harder example:

AAAABBBCCCCDD
You can see that there is an uneven number of consecutive B's, so that means that one of the BB was de-duplicated from the original string. We only need to un-de-duplicate this letter, which gives us:

AAAABBBBCCCCDD


The challenge
Given a non-empty de-duplicated string, consisting of only alphabetic characters (either only uppercase or only lowercase), return the un-de-duplicated string. You can assume that there will always be at least one de-duplicated character in the string.



Test cases
AAABBBCCCCDDDD    -->    AAAABBBBCCCCDDDD
HEY               -->    HHEEYY
AAAAAAA           -->    AAAAAAAA
N                 -->    NN
OOQQO             -->    OOQQOO
ABBB              -->    AABBBB
ABBA              -->    AABBAA

This is code-golf, so the shortest valid submission in bytes wins!

"""

import re

def undedup(s):
    return re.sub(r"(.)\1?", r"\1\1", s)

def main():
    assert(undedup("AAABBBCCCCDDDD") == "AAAABBBBCCCCDDDD")
    assert(undedup("HEY") == "HHEEYY")
    assert(undedup("AAAAAAA") == "AAAAAAAA")
    assert(undedup("N") == "NN")
    assert(undedup("OOQQO") == "OOQQOO")
    assert(undedup("ABBB") == "AABBBB")
    assert(undedup("ABBA") == "AABBAA")

main()

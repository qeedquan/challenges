#!/usr/bin/env python3

"""

Background
As the old saying goes, "I before E, except after C". Whilst we already know exactly how true that saying is, I am a stickler for sayings, especially those that rhyme. I want you to build me an ultra-simple spellchecker which confirms whether or not this vital rule was followed.

The Challenge
Given a string, determine if it:

Never contains the sub-string cie
Never contains the sub-string ei that is not immediately following c
The Rules
Input will be a string of 0 or more lowercase letters and nothing else.
Standard IO applies
Standard Loopholes are forbidden
Test Cases
ceicel    => TRUE
friend    => TRUE
iiee      => TRUE
ie        => TRUE
ceie      => TRUE
eceii     => TRUE
neighbour => FALSE
weight    => FALSE
deficient => FALSE
ieie      => FALSE
ei        => FALSE

"""

import re

def check(s):
    return not re.search("cie|(?<!c)ei", s)

def main():
    assert(check("ceicel") == True)
    assert(check("friend") == True)
    assert(check("iiee") == True)
    assert(check("ie") == True)
    assert(check("ceie") == True)
    assert(check("eceii") == True)
    assert(check("neighbour") == False)
    assert(check("weight") == False)
    assert(check("deficient") == False)
    assert(check("ieie") == False)
    assert(check("ei") == False)

main()

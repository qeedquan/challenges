#!/usr/bin/env python3

"""

Pig-latin is a made-up language that is translated into by moving the first letter of a word to the end and adding ay to the end. For example: hello translates into pig-latin as ellohay. Therefore, translating pig-latin back into English is dropping the ay at the end and moving the last letter to the start (like oodbyegay to goodbye). When writing it out, some people will put a - at the end before moving the first letter for clarity, so it reads (for example) ello-hay instead of ellohay for hello. We will use this hyphenated version for this challenge.

Objective
Undo a pig-latin string.

Instructions
Write a program/function that takes one argument, a single word in the form of a string. If that word is in pig-latin, the program/function must output (i.e. return or print it) the non-pig-latin word. If it isn't pig-latin, output the word as-is.

Pig-latin for this challenge will be in the following format:

ello-hay
If the word ends in -*ay, it is pig-latin, where the * is a single wildcard character.

Non-letter characters should be treated as a normal letter. For multiple dashes, ignore all except the last.

Examples
Using fictitious unpig() Python function for demo.

unpig("ello-hay")    #=> hello
unpig("hello-world") #=> hello-world
unpig("hello")       #=> hello
unpig("pple-aay")    #=> apple
unpig("apple")       #=> apple
unpig("ig-Stay")     #=> ig-Stay (+1 to ETHproductions for noticing.)
unpig("ello----hay") #=> hello---
unpig("la$s-gay")    #=> gla$s
unpig("ig-pay-yay")  #=> yig-pay

Rules
Standard loopholes apply
This is code-golf, so shortest code wins.
Built-in functions (specifically for this purpose) are not permitted.
Use header # Language, XX bytes

"""

import re

def unpig(s):
    return re.sub('(.*)-(.)ay', r'\2\1', s)

def main():
    assert(unpig("ello-hay") == "hello")
    assert(unpig("hello-world") == "hello-world")
    assert(unpig("hello") == "hello")
    assert(unpig("pple-aay") == "apple")
    assert(unpig("ig-Stay") == "ig-Stay")
    assert(unpig("ello----hay") == "hello---")
    assert(unpig("la$s-gay") == "gla$s")
    assert(unpig("ig-pay-yay") == "yig-pay")

main()

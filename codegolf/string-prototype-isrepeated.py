#!/usr/bin/env python3

"""

Many of you must have heard that there is a cooler version of JavaScript in town (read ES6) which has a method String.prototype.repeat so that you can do

"Hello, World!".repeat(3)
and get

"Hello, World!Hello, World!Hello, World!"
as the output.

Your job is to write a function or a program in a language of your choice which detects if a string has been gone under such transformation.

i.e. The input string can be represented as an exact n times repetition of a smaller string. The output (as function's return statement or STDOUT) should be truthy if the string can be or falsy if the string cannot be represented as a repetition of smaller string.

Some sample input:

"asdfasdfasdf"  // true
"asdfasdfa"     // false
"ĴĴĴĴĴĴĴĴĴ"     // true
"ĴĴĴ123ĴĴĴ123"  // true
"abcdefgh"      // false
Note that the last input is false, thus n should be greater than 1

Complete rules

Write a function/program in any language to input (via function argument/command line args/STDIN) a string
Return/Print truthy value if the given string is formed via an exact repetition of a smaller string, repeating at least twice.
Maximum size of the input string is ideally Infinity
String can have all possible ASCII characters
This is a code-golf so smallest code in characters wins.

"""

"""

@xnor

Checks if the string is a substring of itself concatenated twice, eliminating the first and last characters to avoid trivial matches.
If it is, it must be a nontrivial cyclic permutation of itself, and thus the sum of repeated segments.

"""
def repeated(s):
    if s == "":
        return False
    t = s + s
    return s in t[1:len(t)-1]

def main():
    assert(repeated("Hello, World!Hello, World!Hello, World!") == True)
    assert(repeated("asdfasdfasdf") == True)
    assert(repeated("asdfasdfa") == False)
    assert(repeated("ĴĴĴĴĴĴĴĴĴ") == True)
    assert(repeated("ĴĴĴ123ĴĴĴ123") == True)
    assert(repeated("abcdefgh") == False)
    assert(repeated("") == False)
    assert(repeated("aaa") == True)

main()

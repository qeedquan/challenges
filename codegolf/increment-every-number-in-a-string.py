#!/usr/bin/env python3

"""

Given a string containing decimal numbers:

teststring134this 123test string54 100

increment every number in this string by one to give the new string

teststring135this 124test string55 101.

The string can be provided as:

a command line argument
STDIN
a hard-coded variable or function argument
Cover all possible positions for a number:

as a prefix for a word; 123test ► 124test
as a suffix for a word; test123 ► test124
inside a word; te123st ► te124st
alone test 123 test ► test 124 test
Here's a non-golfed solution in Python:

NUMBERS = '0123456789'

def increment(s):
    out = ''

    number = ''
    for c in s:
        if c in NUMBERS:
            number += c
        else:
            if number != '':
                out += str(int(number) + 1)
                number = ''
            out += c

    if number != '':
        out += str(int(number) + 1)
        number = ''

    return out


print "\"%s\"" % (increment('teststring134this 123test string54 100'))

This is a code-golf question, shortest code wins.

"""

def increment(s):
    NUMBERS = "0123456789"
    
    r, x = "", ""
    for c in s:
        if c in NUMBERS:
            x += c
            continue

        if x != "":
            r += str(int(x) + 1)
            x = ""
        r += c

    if x != "":
        r += str(int(x) + 1)

    return r

def main():
    assert(increment("teststring134this 123test string54 100") == "teststring135this 124test string55 101")
    assert(increment("123test") == "124test")
    assert(increment("test123") == "test124")
    assert(increment("te123st") == "te124st")
    assert(increment("test 123 test") == "test 124 test")

main()

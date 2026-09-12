#!/usr/bin/env python3

"""

Given a printable ASCII string, return any letter which is not present (ignoring case), if possible, else return the empty string.

Test Cases:

String => Possible Output
"This is worse than that time I was sus." => "b"
"The quick brown fox jumps over the 'lazy' dog" => ""
"I refuse to participate in the dog slander btw" => "j"
"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ' => ""
"abc" => "d"
Code golf.

"""

def missing(string):
    seen = {}
    for symbol in string:
        seen[symbol.lower()] = True

    for index in range(ord('a'), ord('z') + 1):
        symbol = chr(index)
        if symbol not in seen:
            return str(symbol)
    return ""

def main():
    assert(missing("This is worse than that time I was sus.") == "b")
    assert(missing("The quick brown fox jumps over the 'lazy' dog") == "")
    assert(missing("I refuse to participate in the dog slander btw") == "j")
    assert(missing("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") == "")
    assert(missing("abc") == "d")

main()

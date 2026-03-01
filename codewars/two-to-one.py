#!/usr/bin/env python3

"""

Description:
Take 2 strings s1 and s2 including only letters from a to z. Return a new sorted string (alphabetical ascending), the longest possible, containing distinct letters - each taken only once - coming from s1 or s2.

Examples:
a = "xyaabbbccccdefww"
b = "xxxxyyyyabklmopq"
longest(a, b) -> "abcdefklmopqwxy"

a = "abcdefghijklmnopqrstuvwxyz"
longest(a, a) -> "abcdefghijklmnopqrstuvwxyz"

"""

def longest(s, t):
    c = list(set(s + t))
    c = sorted(c)
    return ''.join(c)

def main():
    assert(longest("xyaabbbccccdefww", "xxxxyyyyabklmopq") == "abcdefklmopqwxy")
    assert(longest("abcdefghijklmnopqrstuvwxyz", "abcdefghijklmnopqrstuvwxyz") == "abcdefghijklmnopqrstuvwxyz")
    assert(longest("aretheyhere", "yestheyarehere") == "aehrsty")
    assert(longest("loopingisfunbutdangerous", "lessdangerousthancoding") == "abcdefghilnoprstu")

main()


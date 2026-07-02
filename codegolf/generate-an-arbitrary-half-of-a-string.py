#!/usr/bin/env python3

"""

Given a string x, we say another string y is half of it, if both of the following properties are true:

y is a (not necessarily continuous) subsequence of x - there exists a strictly increasing sequence ai such that yi=xai
Each character appears in x exactly twice as many times as it appears in y
For example, "acb", "bac" and "bca" are all halves of "baccba", but "abc" and "ac" aren't.

Given a string with English a-z characters (you can choose if you want it lowercase or uppercase), which you are guaranteed all characters appear an even number of times in, output an arbitrary half of it.

Test Cases
"aaaabbbb" -> "aabb"
"abab" -> "ab", "ba"
"aabbaa" -> "aab", "aba", "baa"
"aabbaaaa" -> "aaba", "abaa", "baaa"
"baccba" -> "acb", "bac", "bca", "cba"
"aabbcc" -> "abc"
"abcabc" -> "abc", "acb", "bac", "bca", "cab"

Rules
You can use any reasonable I/O format.
You can print any half of it, or a list containing any non-empty subset of its halves, with or without duplicates.
The distribution of the output can be whatever you want, as long as only valid outputs have a non-zero chance to be selected.
Standard loopholes are disallowed.
This is code golf, so the shortest answer wins.

"""

def f(s):
    if s == "":
        return s
    i = s.count(s[0]) % 2
    return s[:i] + f(s[1:])

def main():
    assert(f("aaaabbbb") in ("aabb"))
    assert(f("abab") in ("ab", "ba"))
    assert(f("aabbaa") in ("aab", "aba", "baa"))
    assert(f("aabbaaaa") in ("aaba", "abaa", "baaa"))
    assert(f("baccba") in ("acb", "bac", "bca", "cba"))
    assert(f("aabbcc") in ("abc"))
    assert(f("abcabc") in ("abc", "acb", "bac", "bca", "cab"))

main()

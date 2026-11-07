#!/usr/bin/env python3

"""

From my CMC.
https://chat.stackexchange.com/transcript/message/59600689#59600689

Given a regex and a non-empty printable ASCII text, return one bit per character in the text, indicating the positions of beginnings of non-overlapping matches, and also the positions of beginnings of sequences that are not part of any non-overlapping matches.

You can:

take the regex as a regex object, string or any other way that is reasonable or allowed by default rules
take the text as a string object, character list, or any other way that is reasonable or allowed by default rules
return the bits as an array, integer, or any other way that is reasonable or allowed by default rules
You may use any flavour, library, or implementation for regexes, as long as you support:

any-character wildcards, e.g. .
positive and negative character classes, e.g. [ab] and [^ab]
repetitions, e.g. a? and a+ and a* and/or the general a{m,n} form
capturing groups, e.g. (ab)
alternatives, e.g. a|b
Examples
[0123456789]+ or [0123456789]{1,}
Hello4the42
10000110010

(aa)+ or (aa){1,}
aaaaaaa
1000001

aaa
baaaab
110010

aaa|b
baaaab
110011

aab? or aab{0,1}
baaaab
110100

x.*z or x.{0,}z
abcdef
100000

 (you can take this as (?:) if necessary)
Hello
11111

[^aeiou]+ or [^aeiou]{1,}
Hello, world!
1110110011000

aaa
aaaaaaa
1001001

10101
101010101
100001000

"""

import re

"""

@loopy walt

Takes a re object and a string and returns a string of 1s and 0s that encodes the mask in binary.

Output is created by bitwise arithmetic.
As we know the leftmost bit is set there are no worries about leading zeros.
Ideally, we would like to or-reduce the set bits.
As there is no short way to do this (is there?) we instead take the sum after eliminating any duplicates.

"""

def solve(regex, string):
    table = {}
    length = 1 << (len(string) - 1)
    for index in regex.finditer(string):
        for shift in index.span():
            table[length >> shift] = True
    return bin(length | sum(table.keys()))[2:]

def main():
    assert(solve(re.compile("[0123456789]+"), "Hello4the42") == "10000110010")
    assert(solve(re.compile("(aa)+"), "aaaaaaa") == "1000001")
    assert(solve(re.compile("aaa"), "baaaab") == "110010")
    assert(solve(re.compile("aaa|b"), "baaaab") == "110011")
    assert(solve(re.compile("aab?"), "baaaab") == "110100")
    assert(solve(re.compile("x.*z"), "abcdef") == "100000")
    assert(solve(re.compile("(?:)"), "Hello") == "11111")
    assert(solve(re.compile("[^aeiou]+"), "Hello, world!") == "1110110011000")
    assert(solve(re.compile("aaa"), "aaaaaaa") == "1001001")
    assert(solve(re.compile("10101"), "101010101") == "100001000")

main()

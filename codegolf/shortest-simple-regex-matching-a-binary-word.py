#!/usr/bin/env python3

"""

Task
Define a simple regex as a non-empty regular expression consisting only of

characters 0 and 1,
grouping parentheses ( and ),
one-or-more repetition quantifier +.
Given a non-empty string of 0s and 1s, your program should find the shortest simple regex matching the full input string. (That is, when matching a simple regex, pretend it’s bookended by ^ and $.) If there are multiple shortest regexes, print any or all of them.)

code-golf, so the shortest submission (in bytes) wins.

Test cases
1 -> 1
00 -> 00 or 0+
010 -> 010
1110 -> 1+0
01010 -> 01010
0101010 -> 0(10)+ or (01)+0
011111 -> 01+
10110110 -> (1+0)+
01100110 -> (0110)+ or (01+0)+
010010010 -> (010)+
111100111 -> 1+001+ or 1+0+1+
00000101010 -> 0+(10)+ or (0+1)+0
1010110001 -> 1(0+1+)+ or (1+0+)+1

"""

import itertools
import re

def binary_regex(s, n=10):
    for r in range(n):
        for i in itertools.combinations("01()+" * (n//2), r):
            t = ''.join(i)
            try:
                if re.fullmatch(t, s) and len(t) <= len(s):
                    return t
            except:
                pass
    return None

def main():
    assert(binary_regex("1") == "1")
    assert(binary_regex("00") == "0+")
    assert(binary_regex("010") == "010")
    assert(binary_regex("1110") == "1+0")
    assert(binary_regex("01010") == "01010")
    assert(binary_regex("0101010") == "0(10)+")
    assert(binary_regex("011111") == "01+")
    assert(binary_regex("10110110") == "(1+0)+")
    assert(binary_regex("010010010") == "(010)+")
    assert(binary_regex("111100111") == "1+0+1+")
    assert(binary_regex("00000101010") == "0+(10)+")
    assert(binary_regex("10110110") == "(1+0)+")
    assert(binary_regex("1010110001") == "1(0+1+)+")

main()

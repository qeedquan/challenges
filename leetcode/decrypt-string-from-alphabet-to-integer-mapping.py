#!/usr/bin/env python3

"""

You are given a string s formed by digits and '#'. We want to map s to English lowercase characters as follows:

Characters ('a' to 'i') are represented by ('1' to '9') respectively.
Characters ('j' to 'z') are represented by ('10#' to '26#') respectively.
Return the string formed after mapping.

The test cases are generated so that a unique mapping will always exist.

Example 1:

Input: s = "10#11#12"
Output: "jkab"
Explanation: "j" -> "10#" , "k" -> "11#" , "a" -> "1" , "b" -> "2".
Example 2:

Input: s = "1326#"
Output: "acz"


Constraints:

1 <= s.length <= 1000
s consists of digits and the '#' letter.
s will be a valid string such that mapping is always possible.

"""

def di(x, y):
    return chr(ord('a') + 10*(ord(x) - ord('0')) + (ord(y) - ord('1')))

def match(s, p):
    if len(s) < len(p):
        return False

    for i in range(len(p)):
        if p[i] == 'd' and not s[i].isnumeric():
            return False
        if p[i] == '#' and s[i] != p[i]:
            return False
    return True

def decrypt(s):
    b = ""
    n = len(s)
    i = 0
    while i < n:
        if match(s[i:], "dd#"):
            b += di(s[i], s[i+1])
            i += 2
        elif match(s[i:], "d"):
            b += di('0', s[i])
        else:
            b += '?'
        i += 1

    return b

def main():
    assert(decrypt("10#11#12") == "jkab")
    assert(decrypt("1326#") == "acz")
    assert(decrypt("25#") == "y")
    assert(decrypt("12345678910#11#12#13#14#15#16#17#18#19#20#21#22#23#24#25#26#") == "abcdefghijklmnopqrstuvwxyz")

main()

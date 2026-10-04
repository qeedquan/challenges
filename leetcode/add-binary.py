#!/usr/bin/env python3

"""

Given two binary strings a and b, return their sum as a binary string.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"


Constraints:

1 <= a.length, b.length <= 10^4
a and b consist only of '0' or '1' characters.
Each string does not contain leading zeros except for the zero itself.

"""

def add(a, b):
    x = int(a, base=2)
    y = int(b, base=2)
    s = str(bin(x + y))
    return s[2:]

def main():
    assert(add("11", "1") == "100")
    assert(add("1010", "1011") == "10101") 
    assert(add("0", "10110") == "10110") 

main()

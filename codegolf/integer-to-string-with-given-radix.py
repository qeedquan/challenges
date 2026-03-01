#!/usr/bin/env python3

"""

Write the shortest function to convert an integer into a numeric representation given a radix between 2 and 62. e.g.:

to_string(351837066319, 31) => "codegolf"

"""

from string import *

def int2radix(n, b):
    s = ""
    while n > 0:
        s = printable[n % b] + s
        n //= b
    return s

def main():
    assert(int2radix(351837066319, 31) == "codegolf")

main()

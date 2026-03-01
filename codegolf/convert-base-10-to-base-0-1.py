#!/usr/bin/env python3

r"""

Base-0.1 mean e.g. 123.45 means in decimal

1*0.1^2 + 2*0.1^1 + 3*0.1^0 + 4*0.1^-1 + 5*0.1^-2

Input and output should match RegEx /\d+(\.\d+)?/. It's required to handle and allowed to output leading and useless trailing zeros.

Test cases (Output not unique and f(f(x)) don't necessary be x)
12.34 <=> 432.1
012 <=> 2.1
3.0 <=> 3.00
Shortest code wins

"""

import re

"""

@STerliakov

Alternative regex-based approach: replace a first occurrence of a digit followed by decimal point or line end with a dot followed by that digit, then reverse and pad with zero.

"""

def conv(x):
    r = re.sub(r'(.)(\.|$)', r'.\1', x, 1)
    r = r[::-1] + '0'
    r = r.strip('0')
    r = r.rstrip('.')
    if r == "":
        r = "0"
    return r

def main():
    assert(conv("12.34") == "432.1")
    assert(conv("012") == "2.1")
    assert(conv("3.0") == "3")
    assert(conv("456") == "6.54")
    assert(conv("0") == "0")

main()

#!/usr/bin/env python3

"""

ATM machines allow 4 or 6 digit PIN codes and PIN codes cannot contain anything but exactly 4 digits or exactly 6 digits.

If the function is passed a valid PIN string, return true, else return false.

Examples (Input --> Output)
"1234"   -->  true
"12345"  -->  false
"a234"   -->  false

"""

import re

def validate(pin):
    regex = re.compile(r'^(\d\d\d\d|\d\d\d\d\d\d)$')
    return regex.match(pin) != None

def main():
    assert(validate("1234") == True)
    assert(validate("12345") == False)
    assert(validate("a234") == False)

main()

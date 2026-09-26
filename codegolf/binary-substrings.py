#!/usr/bin/env python3

"""

Inspired by the fourth problem from BMO2 2009.
https://bmos.ukmt.org.uk/home/bmo2-2009.pdf

Given a positive integer n as input or a parameter, return the number of positive integers whose binary representations occur as blocks in the binary expansion of n.

For example, 13 -> 6 because 13 in binary is 1101 and it has substrings 1101, 110, 101, 11, 10, 1. We do not count binary numbers that start with zero and we do not count zero itself.

Test Cases
13 -> 6
2008 -> 39
63 -> 6
65 -> 7
850 -> 24
459 -> 23
716 -> 22
425 -> 20
327 -> 16
You may take in n as any of the following:

an integer
a list of truthy/falsy values for the binary representation
a string for the binary representation
a base 10 string (though I'm not sure why anyone would do this)
Make your code as short as possible.

"""

def binsub(n):
    r = 0
    for i in range(n):
        if bin(i)[2:] in bin(n):
            r += 1
    return r

def main():
    assert(binsub(13) == 6)
    assert(binsub(2008) == 39)
    assert(binsub(63) == 6)
    assert(binsub(65) == 7)
    assert(binsub(850) == 24)
    assert(binsub(459) == 23)
    assert(binsub(716) == 22)
    assert(binsub(425) == 20)
    assert(binsub(327) == 16)

main()

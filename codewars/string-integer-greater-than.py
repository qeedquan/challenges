#!/usr/bin/env python3

"""

You are to write a function, stringIntGreaterThan that must accept arguments, each being the string representation of an positive or negative integer of any length (could contain a thousand digits, or more; also, integers will not have leading zeros).

The function should then return true if the first argument is greater than the second argument, false if not.

"""

def stringIntGreaterThan(a, b):
    return int(a) > int(b)

def main():
    assert(stringIntGreaterThan("1", "2") == False)
    assert(stringIntGreaterThan("5", "4") == True)
    assert(stringIntGreaterThan("234", "134") == True)
    assert(stringIntGreaterThan("1345345", "134534") == True)
    assert(stringIntGreaterThan("1345345", "345345") == True)

main()

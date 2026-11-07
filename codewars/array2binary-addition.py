#!/usr/bin/env python3

"""

Given an array containing only integers, add all the elements and return the binary equivalent of that sum.

If the array contains any non-integer element (e.g. an object, a float, a string and so on), return false.

Note: The sum of an empty array is zero.

arr2bin([1,2]) == '11'
arr2bin([1,2,'a']) == false

"""

def arr2bin(a):
    r = 0
    for v in a:
        if not isinstance(v, int):
            return False
        r += v
    return bin(r)[2:]

def main():
    assert(arr2bin([1, 2]) == "11")
    assert(arr2bin([1, 2, 'a']) == False)

main()

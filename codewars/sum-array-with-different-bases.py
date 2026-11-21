#!/usr/bin/env python3

"""

You get an array of different numbers to sum up. But there is one problem, those numbers all have different bases. For example:

You get an array of numbers with their base as an input:

[["101",16],["7640",8],["1",9]]

The output should be the sum as an integer value with a base of 10, so according to the example this would be:

4258

A few more examples:
[["101",2], ["10",8]] --> 13
[["ABC",16], ["11",2]] --> 2751

Bases can be between 2 and 36 (2<=base<=36)

"""

def sumitup(array):
    total = 0
    for values in array:
        total += int(values[0], values[1])
    return total

def main():
    assert(sumitup([["101", 16], ["7640", 8], ["1", 9]]) == 4258)
    assert(sumitup([["101", 2], ["10", 8]]) == 13)
    assert(sumitup([["ABC", 16], ["11", 2]]) == 2751)

main()

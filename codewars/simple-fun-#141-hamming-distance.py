#!/usr/bin/env python3

"""

Task
The hamming distance between a pair of numbers is the number of binary bits that differ in their binary notation.

Example
For a = 25, b= 87, the result should be 4

25: 00011001
87: 01010111
The hamming distance between these two would be 4 ( the 2nd, 5th, 6th, 7th bit ).

Input/Output
[input] integer a
First Number. 1 <= a <= 2^20

[input] integer b
Second Number. 1 <= b <= 2^20

[output] an integer
Hamming Distance

"""

def hamming_distance(a, b):
    return (a ^ b).bit_count()

def main():
    assert(hamming_distance(25, 87) == 4)
    assert(hamming_distance(256, 302) == 4)
    assert(hamming_distance(543, 634) == 4)
    assert(hamming_distance(34013, 702) == 7)

main()

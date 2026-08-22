#!/usr/bin/env python3

"""

Implement NumberToPattern
Convert an integer to its corresponding DNA string.

Given: Integers index and k.

Return: NumberToPattern(index, k).

Sample Dataset
45
4
Sample Output
AGTC

"""

def number_to_pattern(n, k):
    bases = "ACGT"

    p = ""
    for _ in range(k):
        p += bases[n & 3]
        n >>= 2
    return p[::-1]

def main():
    assert(number_to_pattern(45, 4) == "AGTC")

main()

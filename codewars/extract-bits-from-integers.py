#!/usr/bin/env python3

"""

Given BigInt variable extract length of bits starting from least significant bit* and skipping offset of bits. For convenience sake only first 64 bits of input variable will be used for encoding value. offset and length may be arbitrarily large.

All input values will be non-negative.

Examples

input	                               offset	        length	    result
0xAF	                                 4	             0	       0x0
0xAF	                                 0	             4	       0xF
0xAF	                                 4	             4	       0xA
0xAB00EF	                             4	             16	       0xB00E
0xAA00BB00CC	                     0xF0000000	        0x64	     0x0

*LSb - Least Significant bit - bit denoting smallest value in the number i.e. 0 or 1.

"""

def extract_bits(field, offset, length):
    return (field >> offset) - (((field >> offset) >> length) << length)

def main():
    assert(extract_bits(0xAF, 4, 0) == 0x0)
    assert(extract_bits(0xAF, 0, 4) == 0xF)
    assert(extract_bits(0xAF, 4, 4) == 0xA)
    assert(extract_bits(0xAB00EF, 4, 16) == 0xB00E)
    assert(extract_bits(0xAA00BB00CC, 0xF0000000, 0x64) == 0x0)

main()

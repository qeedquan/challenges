#!/usr/bin/env python3

"""

The objective is to write a method that takes two integer parameters and returns a single integer equal to the number of 1s in the binary representation of the greatest common divisor of the parameters.

Taken from Wikipedia: "In mathematics, the greatest common divisor (gcd) of two or more integers, when at least one of them is not zero, is the largest positive integer that divides the numbers without a remainder. For example, the GCD of 8 and 12 is 4."

For example: the greatest common divisor of 300 and 45 is 15. The binary representation of 15 is 1111, so the correct output would be 4.

If both parameters are 0, the method should return 0. The function must be able to handle negative input.

"""

from math import gcd

def gcdbin(a, b):
    return gcd(a, b).bit_count()

def main():
	assert(gcdbin(300, 45) == 4)
	assert(gcdbin(666666, 333111) == 6)
	assert(gcdbin(545034, 5) == 1)
	assert(gcdbin(0, 0) == 0)
	assert(gcdbin(0, 76899299) == 14)
	assert(gcdbin(-124, -16) == 1)

main()

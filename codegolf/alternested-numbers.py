#!/usr/bin/env python3

"""

Consider the array of positive integers:

1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, ...
Then, concatenate them:

1234567891011121314151617181920212223242526...
And then split them into chunks of variable length, each length being equal to the Nth positive integer:

[1][23][456][7891][01112][131415][1617181][92021222][324252627][2829303132] ...
---------------------------------------------------------------------------
 1  2    3     4     5       6       7        8          9          10      ...
Task
Given an integer N (positive for 1-indexing or non-negative for 0-indexing), your task is to output the sum of the deltas of the digits in the Nth chunk (the differences between consecutive digits).

Default-forbidden loopholes apply.

Standard Input and Output methods apply.

You may choose either 0 or 1-indexing for N.

The sequence must start with 1.

This is code-golf, shortest code in bytes wins.

Examples & Test cases
1-indexed test cases. If you want 0-indexed ones, just decrement N.

N, Chunk, Deltas, Sum

1  -> 1          -> []                               -> 0
2  -> 23         -> [1]                              -> 1
3  -> 456        -> [1, 1]                           -> 2
4  -> 7891       -> [1, 1, -8]                       -> -6
5  -> 01112      -> [1, 0, 0,1]                      -> 2
6  -> 131415     -> [2, -2, 3, -3, 4]                -> 4
7  -> 1617181    -> [5, -5, 6, -6, 7, -7]            -> 0
8  -> 92021222   -> [-7, -2, 2, -1, 1, 0, 0]         -> -7
9  -> 324252627  -> [-1, 2, -2, 3, -3, 4, -4, 5]     -> 4
10 -> 2829303132 -> [6, -6, 7, -6, -3, 3, -2, 2, -1] -> 0

Puzzle 2 on CodeGolf-Hackathon (I am the original author there too, so I am allowed to repost). Related, Inspiration. Related.

"""

# Ported from @lynn solution
def alternest(n):
	concat = "".join(str(i) for i in range(n*n + 1))
	digits = [int(digit) for digit in concat]
	first = n*(n + 1)//2
	second = n*(n - 1)//2 + 1
	return digits[first] - digits[second]

def main():
	assert(alternest(1) == 0)
	assert(alternest(2) == 1)
	assert(alternest(3) == 2)
	assert(alternest(4) == -6)
	assert(alternest(5) == 2)
	assert(alternest(6) == 4)
	assert(alternest(7) == 0)
	assert(alternest(8) == -7)
	assert(alternest(9) == 4)
	assert(alternest(10) == 0)

main()

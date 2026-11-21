#!/usr/bin/env python3

"""

A follow-up to this challenge
https://codegolf.stackexchange.com/questions/144146/frequency-distribution-of-multiple-dice-rolls

Given a set of mixed dice, output the frequency distribution of rolling all of them and summing the rolled numbers on each die.

For example, consider 1d12 + 1d8 (rolling 1 12-sided die and 1 8-sided die). The maximum and minimum rolls are 20 and 2, respectively, which is similar to rolling 2d10 (2 10-sided dice). However, 1d12 + 1d8 results in a flatter distribution than 2d10: [1, 2, 3, 4, 5, 6, 7, 8, 8, 8, 8, 8, 7, 6, 5, 4, 3, 2, 1] versus [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1].

Rules
The frequencies must be listed in increasing order of the sum to which the frequency corresponds.
Labeling the frequencies with the corresponding sums is allowed, but not required (since the sums can be inferred from the required order).
You do not have to handle inputs where the output exceeds the representable range of integers for your language.
Leading or trailing zeroes are not permitted. Only positive frequencies should appear in the output.
You may take the input in any reasonable format (list of dice ([6, 8, 8]), list of dice pairs ([[1, 6], [2, 8]]), etc.).
The frequencies must be normalized so that the GCD of the frequencies is 1 (e.g. [1, 2, 3, 2, 1] instead of [2, 4, 6, 4, 2]).
All dice will have at least one face (so a d1 is the minimum).
This is code-golf, so the shortest code (in bytes) wins. Standard loopholes are forbidden, as per usual.
Test Cases
These test cases are given as input: output, where the input is given as a list of pairs [a, b] representing a b-sided dice (so [3, 8] refers to 3d8, and [[1, 12], [1, 8]] refers to 1d12 + 1d8).

[[2, 10]]: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1]
[[1, 1], [1, 9]]: [1, 1, 1, 1, 1, 1, 1, 1, 1]
[[1, 12], [1, 8]]: [1, 2, 3, 4, 5, 6, 7, 8, 8, 8, 8, 8, 7, 6, 5, 4, 3, 2, 1]
[[2, 4], [3, 6]]: [1, 5, 15, 35, 68, 116, 177, 245, 311, 363, 392, 392, 363, 311, 245, 177, 116, 68, 35, 15, 5, 1]
[[1, 3], [2, 13]]: [1, 3, 6, 9, 12, 15, 18, 21, 24, 27, 30, 33, 36, 37, 36, 33, 30, 27, 24, 21, 18, 15, 12, 9, 6, 3, 1]
[[1, 4], [2, 8], [2, 20]]: [1, 5, 15, 35, 69, 121, 195, 295, 423, 579, 761, 965, 1187, 1423, 1669, 1921, 2176, 2432, 2688, 2944, 3198, 3446, 3682, 3898, 4086, 4238, 4346, 4402, 4402, 4346, 4238, 4086, 3898, 3682, 3446, 3198, 2944, 2688, 2432, 2176, 1921, 1669, 1423, 1187, 965, 761, 579, 423, 295, 195, 121, 69, 35, 15, 5, 1]
[[1, 10], [1, 12], [1, 20], [1, 50]]: [1, 4, 10, 20, 35, 56, 84, 120, 165, 220, 285, 360, 444, 536, 635, 740, 850, 964, 1081, 1200, 1319, 1436, 1550, 1660, 1765, 1864, 1956, 2040, 2115, 2180, 2235, 2280, 2316, 2344, 2365, 2380, 2390, 2396, 2399, 2400, 2400, 2400, 2400, 2400, 2400, 2400, 2400, 2400, 2400, 2400, 2399, 2396, 2390, 2380, 2365, 2344, 2316, 2280, 2235, 2180, 2115, 2040, 1956, 1864, 1765, 1660, 1550, 1436, 1319, 1200, 1081, 964, 850, 740, 635, 536, 444, 360, 285, 220, 165, 120, 84, 56, 35, 20, 10, 4, 1]

"""

import numpy as np
from functools import reduce

"""

@flawr

The observation here is that the distribution of e.g. a 3-sided and a 5-sided dice
is the discrete convolution of the two vectors [1,1,1] and [1,1,1,1,1].

@Misha Lavrov

This is the convolution-based approach (here, we take convolutions via the product of generating functions - 1+x+x^2+...+x^(N-1)
is the generating function for rolling a dN - and then take the list of coefficients).

"""

def solve(a):
    p = []
    for x, y in a:
        for _ in range(x):
            p.append(np.ones(y))
    return reduce(np.convolve, p).astype(int).tolist()

def main():
    assert(solve([[2, 10]]) == [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1])
    assert(solve([[1, 1], [1, 9]]) == [1, 1, 1, 1, 1, 1, 1, 1, 1])
    assert(solve([[1, 12], [1, 8]]) == [1, 2, 3, 4, 5, 6, 7, 8, 8, 8, 8, 8, 7, 6, 5, 4, 3, 2, 1])
    assert(solve([[2, 4], [3, 6]]) == [1, 5, 15, 35, 68, 116, 177, 245, 311, 363, 392, 392, 363, 311, 245, 177, 116, 68, 35, 15, 5, 1])
    assert(solve([[1, 3], [2, 13]]) == [1, 3, 6, 9, 12, 15, 18, 21, 24, 27, 30, 33, 36, 37, 36, 33, 30, 27, 24, 21, 18, 15, 12, 9, 6, 3, 1])
    assert(solve([[1, 4], [2, 8], [2, 20]]) == [1, 5, 15, 35, 69, 121, 195, 295, 423, 579, 761, 965, 1187, 1423, 1669, 1921, 2176, 2432, 2688, 2944, 3198, 3446, 3682, 3898, 4086, 4238, 4346, 4402, 4402, 4346, 4238, 4086, 3898, 3682, 3446, 3198, 2944, 2688, 2432, 2176, 1921, 1669, 1423, 1187, 965, 761, 579, 423, 295, 195, 121, 69, 35, 15, 5, 1])
    assert(solve([[1, 10], [1, 12], [1, 20], [1, 50]]) == [1, 4, 10, 20, 35, 56, 84, 120, 165, 220, 285, 360, 444, 536, 635, 740, 850, 964, 1081, 1200, 1319, 1436, 1550, 1660, 1765, 1864, 1956, 2040, 2115, 2180, 2235, 2280, 2316, 2344, 2365, 2380, 2390, 2396, 2399, 2400, 2400, 2400, 2400, 2400, 2400, 2400, 2400, 2400, 2400, 2400, 2399, 2396, 2390, 2380, 2365, 2344, 2316, 2280, 2235, 2180, 2115, 2040, 1956, 1864, 1765, 1660, 1550, 1436, 1319, 1200, 1081, 964, 850, 740, 635, 536, 444, 360, 285, 220, 165, 120, 84, 56, 35, 20, 10, 4, 1])

main()

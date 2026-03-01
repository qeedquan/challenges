#!/usr/bin/env python3

"""

Background
For this challenge, a 'metasequence' will be defined as a sequence of numbers where not only the numbers themselves will increase, but also the increment, and the increment will increase by an increasing value, etc.

For instance, the tier 3 metasequence would start as:

1 2 4 8 15 26 42 64 93 130 176

because:

    1 2 3  4  5  6  7  8   9       >-|
      ↓+↑ = 7                        | Increases by the amount above each time
  1 2 4 7  11 16 22 29 37  46  >-| <-|
                                 | Increases by the amount above each time
1 2 4 8 15 26 42 64 93 130 176 <-|

Challenge
Given a positive integer, output the first twenty terms of the metasequence of that tier.

Test cases
Input: 3 Output: [ 1, 2, 4, 8, 15, 26, 42, 64, 93, 130, 176, 232, 299, 378, 470, 576, 697, 834, 988, 1160 ]

Input: 1 Output: [ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20 ]

Input: 5 Output: [ 1, 2, 4, 8, 16, 32, 63, 120, 219, 382, 638, 1024, 1586, 2380, 3473, 4944, 6885, 9402, 12616, 16664 ]

Input: 13 Output: [ 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16383, 32752, 65399, 130238, 258096, 507624 ]

As you may realise, the first t+1 items of each sequence of tier t are the first t+1 powers of 2...

Rules
Standard loopholes apply
This is code-golf, so shortest answer in bytes wins

"""


from math import *

"""

@alephalpha

meta-sequence[n](i) = Sum[k=0, n] binomial(i, k)

"""

def metasequence(n):
    r = []
    for i in range(0, 20):
        v = 0
        for j in range(n + 1):
            v += comb(i, j)
        r.append(v)
    return r

def main():
    assert(metasequence(3) == [1, 2, 4, 8, 15, 26, 42, 64, 93, 130, 176, 232, 299, 378, 470, 576, 697, 834, 988, 1160])
    assert(metasequence(1) == [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20])
    assert(metasequence(5) == [1, 2, 4, 8, 16, 32, 63, 120, 219, 382, 638, 1024, 1586, 2380, 3473, 4944, 6885, 9402, 12616, 16664])
    assert(metasequence(13) == [1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16383, 32752, 65399, 130238, 258096, 507624])

main()

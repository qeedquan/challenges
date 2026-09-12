#!/usr/bin/env python3

"""

We say two positive integers are anagrams of each other if the digits in one of them (in decimal representation) can be rearranged to form the other. Leading zeros don't count. For example, 110020222 is an anagram of 212102020, but not of 221100011; neither is 22002211 even though it can be written as 022002211.

Interestingly enough, every arithmetic sequence of positive integers contains arbitrarily large sets of elements, all anagrams of each other. In this challenge, we use a special case of this fact.

Task
For this challenge, you have to write a program or function in a language of your choice, that takes as input two positive integers: k and N, and outputs N different positive integers, all of which are multiples of k and anagrams of each other.

Rules
You can assume N is bigger than 1.
Input and output can be taken in any of the standard ways.
Standard loopholes are forbidden.
Output may contain spaces and newlines.
Winning Criterion
This is code-golf, so shortest code in bytes wins.

Examples
Note that there are more than one possible output (infinitely many, in fact) given any k and N. Here are some examples:

  k  |   N   |  Possible output
-----+-------+------------------
  9  |   4   |  234
     |       |  243
     |       |  342
     |       |  432
-----+-------+------------------
 351 |   6   | 142857
     |       | 428571
     |       | 285714
     |       | 857142
     |       | 571428
     |       | 714285

"""

import sys

"""

Ported from @xnor solution

For example, k=12,n=4 produces this list of numbers, written out in lines for clarity, with the ...'s hiding a big string of zeroes:

1200...0000012
1200...0000120
1200...0001200
1200...0012000
So, we have a prefix of k, followed by another k in a position that moves one place left each time, and the rest zeroes. We need the prefix because leading zeroes aren't allowed for the anagrams, so we make it so that all the outputs have the same number of digits.

We leave enough zeroes to ensure that the right string to never bump into the left one. N**k zeroes more than suffices for this, giving extremely big numbers; N+k or even N+log_10(k) would be enough. Note that Python right-associates 10**N**k as 10**(N**k).

Unfortunately this variable bound doesn't lend well to recursive solutions that update k as they go. An upper bound on how big k can be, even if enormous, would simplify this.

"""

def solve(k, N):
    return [k*(10**(N**k) + 10**i) for i in range(N)]


def main():
    sys.set_int_max_str_digits(1000000)
    print(solve(9, 4))
    print(solve(351, 6))

main()

#!/usr/bin/env python3

"""

A rhyme scheme is the pattern of rhymes at the end of the lines in a poem. They are typically represented using letters, like ABAB. We consider two rhyme schemes identical if they are isomorphs, and therefore only report the lexicographically earliest. Equivalently, rhyme schemes are simply strings in standard order. The rhyme schemes of length 4 are:

AAAA, AAAB, AABA, AABB, AABC, ABAA, ABAB, ABAC, ABBA, ABBB, ABBC, ABCA, ABCB, ABCC, ABCD
A complete rhyme scheme is one where every line rhymes with at least one other line; that is, every letter in the string appears more than once. For length 4, these are:

AAAA, AABB, ABAB, ABBA
Now consider the sequence of the number of complete rhyme schemes for any length. With length 0, 2, or 3, there is exactly one way to do this ('', AA, and AAA respectively), and length 1 has no ways. As we see, length 4 gives 4 ways. The first 30 terms of this sequence are:

1, 0, 1, 1, 4, 11, 41, 162, 715, 3425, 17722, 98253, 580317, 3633280, 24011157, 166888165, 1216070380, 9264071767, 73600798037, 608476008122, 5224266196935, 46499892038437, 428369924118314, 4078345814329009, 40073660040755337, 405885209254049952, 4232705122975949401, 45398541400642806873, 500318506535417182516, 5660220898064517469939
This is A000296 in the OEIS. It is also the number of ways to partition a set into subsets of a size of at least 2.

Your task is to output this sequence.

The sequence should not be limited by the 26 letters in the alphabet; the letters can be abstracted such that the sequence continues infinitely. The complete rhyme schemes which use the digits 1-9 is OEIS A273978.

Rules
As with standard sequence challenges, you may choose to either:
Take an input n and output the nth term of the sequence
Take an input nand output the first n terms
Output the sequence indefinitely, e.g. using a generator
You may use 0- or 1-indexing
You may use any standard I/O method
Standard loopholes are forbidden
This is code-golf, so the shortest code in bytes wins

"""

from math import *

def memoized(f):
    memo = {}
    def m_fun(*args):
        if args in memo:
            return memo[args]
        res = f(*args)
        memo[args] = res
        return res

    return m_fun

# https://oeis.org/A000296
@memoized
def rhymes(n):
    if n < 0:
        return 0

    if n == 0:
        return 1

    r = 0
    for i in range(1, n):
        r += comb(n - 1, i) * rhymes(n - 1 - i)
    return r

def main():
    tab = [1, 0, 1, 1, 4, 11, 41, 162, 715, 3425, 17722, 98253, 580317, 3633280, 24011157, 166888165, 1216070380, 9264071767, 73600798037, 608476008122, 5224266196935, 46499892038437, 428369924118314, 4078345814329009, 40073660040755337, 405885209254049952, 4232705122975949401, 45398541400642806873, 500318506535417182516, 5660220898064517469939]

    for i in range(len(tab)):
        assert(rhymes(i) == tab[i])

main()

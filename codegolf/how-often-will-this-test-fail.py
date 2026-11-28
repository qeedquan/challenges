#!/usr/bin/env python3

"""

Preamble
There was a unit test in our codebase which was shuffling a string of length 52 formed from the set of letters [A−Z]+[A−Z] and then using the first 20 characters of that shuffled string.
It failed quite a while after being written due to no repeated character being present in those twenty and we wondered how often such a test would be likely to fail. (A little more than one in five hundred and twenty-two times it turns out).

Challenge
Given an alphabet size (a), a number (n) of occurrences of each letter, and a prefix length (p), output the probability that a (uniformly chosen) random permutation of the a×n letters begins with p distinct letters.

You may assume that:

There will be enough letters to make the prefix: p≤n×a
Each of the three inputs will be non-negative integers: p,n,a∈Z≥0
Output in any reasonable format - e.g. a float, a fraction, a pair containing the numerator and denominator (no requirement to simplify); if you're unsure, just ask!

Potential method
This is the method we used to calculate the result we were interested in (from the preamble).

If one thinks of the n×a elements as a bag from which one repeatedly picks the next element of the prefix,
then the probability of extending the prefix by one element such that it remains fully distinct is the number of elements remaining in the bag which do not yet appear in the prefix divided by the total number of elements remaining in the bag.
As such the probability that the final length p prefix will be fully distinct is the product of these probabilities starting with a full bag and an empty prefix:

Prod[i=0, n-1] n*(a-i) / (n*a-i)

Test cases

Floating point inaccuracy is acceptable; fractions, if used, do not need to be in simplest form.
Ideally these test cases will all be runnable in a reasonable amount of time, but if golf means crazy inefficiency so be it!

 a   n   p    output                          (as a fraction)
 2   1   0    1                               (1/1)
 2   1   1    1                               (1/1)
 2   1   2    1                               (1/1)
50   1  50    1                               (1/1)
 3   2   0    1                               (1/1)
 3   2   1    1                               (1/1)
 3   2   2    0.8                             (4/5)
 3   2   3    0.4                             (2/5)
 3   2   4    0                               (0/1)
26   2   0    1                               (1/1)
26   2   1    1                               (1/1)
26   2   2    0.9803921568627451              (50/51)
26   2  13    0.13417306435734888             (77824/580027)
26   2  20    0.001916063061695329            (2097152/1094510949)
32   8  11    0.1777403166811693              (31138512896/175191051065)
32   8  22    0.00014139946994082153          (3477211257894250479616/24591402353555723779476075)
32   8  33    0                               (0/1)

"""

from math import *

"""

@ShreevatsaR

Just for completeness, a combinatorial proof of the equivalent formula: There are n copies of each of a letters; call them "tiles", as in Scrabble tiles.
If you consider the an tiles in a bag, there are binomial(a*n, p) ways of drawing p letters from the bag - that's the denominator.
The number of ways of picking them all distinct is: binomial(a, p) ways of choosing which letters of the alphabet are in the set of p, multiplied by n choices of tile for each of those letters, giving the numerator binomial(a, p)*n**p
and the probability binomial(a, p)*n**p / binomial(a*n, p)

"""
def prob(a, n, p):
    x = comb(a, p) * n**p
    y = comb(a*n, p)
    d = gcd(x, y)
    return (x//d, y//d)

def main():
    assert(prob(2, 1, 0) == (1, 1))
    assert(prob(2, 1, 1) == (1, 1))
    assert(prob(2, 1, 2) == (1, 1))
    assert(prob(50, 1, 50) == (1, 1))
    assert(prob(3, 2, 0) == (1, 1))
    assert(prob(3, 2, 1) == (1, 1))
    assert(prob(3, 2, 2) == (4, 5))
    assert(prob(3, 2, 3) == (2, 5))
    assert(prob(3, 2, 4) == (0, 1))
    assert(prob(26, 2, 0) == (1, 1))
    assert(prob(26, 2, 1) == (1, 1))
    assert(prob(26, 2, 2) == (50, 51))
    assert(prob(26, 2, 13) == (77824, 580027))
    assert(prob(26, 2, 20) == (2097152, 1094510949))
    assert(prob(32, 8, 11) == (31138512896, 175191051065))
    assert(prob(32, 8, 22) == (3477211257894250479616, 24591402353555723779476075))
    assert(prob(32, 8, 33) == (0, 1))

main()

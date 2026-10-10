#!/usr/bin/env python3

"""

A deck of cards is the Cartesian product of S suits and R ranks. Many, though not all, card games use S=4 and R∊{6,8,13}. A hand of H cards is dealt from the deck. Its distribution, a.k.a. "hand pattern", is an array that describes how many cards you got from each suit, ignoring suit order (so, it's like a multi-set). Given a distribution D satisfying len(D)=S, 1≤sum(D)=H≤S×R, 0≤D[i]≤R, D[i]≥D[i+1], find the probability of it occurring.

Input: an integer R and an array D.

Output: the probability with at least 5 digits after the decimal mark; trailing zeroes may be skipped; scientific notation is ok.

Loopholes forbidden. Shortest wins.

Tests:

R    D               probability
13   4 4 3 2     ->  0.2155117564516334148528314355068773
13   5 3 3 2     ->  0.1551684646451760586940386335649517
13   9 3 1 0     ->  0.0001004716813294328274372174524508
13   13 0 0 0    ->  0.0000000000062990780897964308603403
8    3 2 2 1     ->  0.4007096203759162602321667950144035
8    4 2 1 1     ->  0.1431105787056843786543452839337155
8    2 2 1 0     ->  0.3737486095661846496106785317018910
8    3 1 1 0     ->  0.2135706340378197997775305895439377
15   4 4 3 2 1   ->  0.1428926269185580521441708109954798
10   3 0 0       ->  0.0886699507389162561576354679802956
10   2 1 0       ->  0.6650246305418719211822660098522167
10   1 1 1       ->  0.2463054187192118226600985221674877
See also Bridge hand patterns in Wikipedia.

EDIT: dropped unnecessary restriction H≤R

EDIT: added constraint H≥1

"""

from math import comb

"""

@orlp

Formula is the product of binom(R, d) for each element d in D, times factorial(len(D)), divided by the product of factorial(len(S)) for each S in the groupings of D (e.g. [4, 4, 3, 2] has groupings [[4, 4], [3], [2]]), finally divided by binom(len(D) * R, sum(D)).

Or in math notation, assuming m contains the multiplicities of the n unique elements in D:

|D|!/(m_1! * m_2! * ... m_n!) * binomial(|D|*R, Sum D)^-1 * Product[d in D] binomial(R, d)

"""
def f(R, D, i=1, s=1, t=0):
    if len(D) > 0:
        X = comb(R, D[0]) * i/s
        Y = f(R, D[1:], i + 1, (D[0] in D[1:])*s + 1, t+D[0])
        return X * Y
    return 1 / comb((i - 1) * R, t)

def test(R, D, r):
    v = f(R, D)
    print(v)
    assert(abs(v - r) < 1e-12)

def main():
    test(13, [4, 4, 3, 2], 0.2155117564516334148528314355068773)
    test(13, [5, 3, 3, 2], 0.1551684646451760586940386335649517)
    test(13, [9, 3, 1, 0], 0.0001004716813294328274372174524508)
    test(13, [13, 0, 0, 0], 0.0000000000062990780897964308603403)
    test(8, [3, 2, 2, 1], 0.4007096203759162602321667950144035)
    test(8, [4, 2, 1, 1], 0.1431105787056843786543452839337155)
    test(8, [2, 2, 1, 0], 0.3737486095661846496106785317018910)
    test(8, [3, 1, 1, 0], 0.2135706340378197997775305895439377)
    test(15, [4, 4, 3, 2, 1], 0.1428926269185580521441708109954798)
    test(10, [3, 0, 0], 0.0886699507389162561576354679802956)
    test(10, [2, 1, 0], 0.6650246305418719211822660098522167)
    test(10, [1, 1, 1], 0.2463054187192118226600985221674877)

main()

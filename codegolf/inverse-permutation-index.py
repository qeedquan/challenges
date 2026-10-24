#!/usr/bin/env python3

"""

Introduction
The lexicographical permutations of a list with n elements can be numbered from 0 to n! - 1. For example, the 3! = 6 permutations of (1,2,3) would be (1,2,3), (1,3,2), (2,1,3), (2,3,1), (3,1,2), (3,2,1).

When a permutation is applied to a list, its elements are ordered in the same order as the numbers in the permutation. For example, applying the permutation (2,3,1) to l = (a,b,c) yields (l[2],l[3],l[1]) = (b,c,a).

The inverse of a permutation is defined as the permutation that reverses this operation, i.e. applying a permutation and then its inverse (or vice versa) does not modify the array. For example, the inverse of (2,3,1) is (3,1,2), since applying that to (b,c,a) yields (a,b,c).

Also, a permutation's inverse applied to the permutation itself yields the integers 1…n. For example, applying (3,1,2) to (2,3,1) yields (1,2,3).

We now define the function revind(x) as the index of the inverse permutation of the permutation with index x. (This is A056019, if you're interested.)

Since a permutation with index i only modifies the last k items of the list iff 0 ≤ i < k!, we can add any number of elements to the start of the list without affecting revind(i). Therefore the length of the list does not affect the result.

Challenge
Your task is to implement revind(x). You will write a full program or function that takes a single nonnegative integer x as input/argument and outputs/returns the result as a single nonnegative integer.

The input and output may be 0-indexed or 1-indexed, but this must be consistent between them.

Builtins that generate permutations by index, return the index of a permutation or find the inverse permutation are banned. (Builtins that generate all permutations or the next permutation are allowed.)

Standard code-golf rules apply.

Examples
The examples below are 0-indexed.

Input    Output
0        0
1        1
2        2
3        4
4        3
5        5
6        6
13       10
42       51
100      41
1000     3628
2000     3974
10000    30593
100000   303016

Reference implementation (Python 3)
def revind(n):
    from math import factorial
    from itertools import permutations, count
    l = next(filter(lambda x: factorial(x) > n, count(1)))
    pms = list(permutations(range(l)))
    return [k for k in range(len(pms)) if tuple(pms[n][i] for i in pms[k]) == pms[0]][0]

"""

from math import *
from itertools import *

# https://oeis.org/A056019
def revind(n):
    l = next(filter(lambda x: factorial(x) > n, count(1)))
    pms = list(permutations(range(l)))
    return [k for k in range(len(pms)) if tuple(pms[n][i] for i in pms[k]) == pms[0]][0]

def main():
    tab = [0, 1, 2, 4, 3, 5, 6, 7, 12, 18, 13, 19, 8, 10, 14, 20, 16, 22, 9, 11, 15, 21, 17, 23, 24, 25, 26, 28, 27, 29, 48, 49, 72, 96, 73, 97, 50, 52, 74, 98, 76, 100, 51, 53, 75, 99, 77, 101, 30, 31, 36, 42, 37, 43, 54, 55, 78, 102, 79, 103, 60, 66, 84, 108, 90, 114, 61, 67, 85]

    assert(revind(0) == 0)
    assert(revind(1) == 1)
    assert(revind(2) == 2)
    assert(revind(3) == 4)
    assert(revind(4) == 3)
    assert(revind(5) == 5)
    assert(revind(6) == 6)
    assert(revind(13) == 10)
    assert(revind(42) == 51)
    assert(revind(100) == 41)
    assert(revind(1000) == 3628)
    assert(revind(2000) == 3974)
    assert(revind(10000) == 30593)
    assert(revind(100000) == 303016)

    for i in range(len(tab)):
        assert(revind(i) == tab[i])

main()

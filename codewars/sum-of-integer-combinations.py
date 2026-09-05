#!/usr/bin/env python3

"""

Consider the array [3,6,9,12]. If we generate all the combinations with repetition that sum to 12, we get 5 combinations: [12], [6,6], [3,9], [3,3,6], [3,3,3,3]. The length of the sub-arrays (such as [3,3,3,3] should be less than or equal to the length of the initial array ([3,6,9,12]).

Given an array of positive integers and a number n, count all combinations with repetition of integers that sum to n. For example:

find([3,6,9,12],12) = 5.
More examples in the test cases.

Good luck!

"""

import itertools

def find(a, t):
    m = {}
    c = 0
    for i in range(1, len(a) + 1):
        for p in itertools.product(a, repeat=i):
            k = tuple(sorted(p))
            if k not in m and sum(p) == t:
                c += 1
            m[k] = True
    return c

def main():
    assert(find([3, 6, 9, 12], 12) == 5)
    assert(find([1, 2, 3], 10) == 0)
    assert(find([1, 2, 3], 7) == 2)
    assert(find([1, 2, 3], 5) == 3)
    assert(find([3, 6, 9, 12], 12) == 5)
    assert(find([1, 4, 5, 8], 8) == 3)
    assert(find([3, 6, 9, 12], 15) == 5)
    assert(find([3, 6, 9, 12, 14, 18], 30) == 21)

main()

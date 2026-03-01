#!/usr/bin/env python3

"""

List all of the combinations with replacement (or combinations with repetition) of size k from a set of n elements.

A combination with replacement is an unordered multiset that every element in it are also in the set of n elements. Note that:

It is unordered. So a previously printed set with a different order shouldn't be printed again.
It is a multiset. The same element can (but isn't required to) appear more than once. This is the only difference between a combination with replacement and a normal combination.
The set should have exactly k elements.
Alternatively, it is also a size-k subset of the multiset which contains each of the n elements k times.

The input should be either n and k, where the elements are the first n positive or non-negative integers, or the n elements and k, where you can assume the n elements are all different from each other.

The output should be a list of all the combinations with replacement with size k from the given set. You can print them and the elements in each of them in any order.

You may not use builtins generating combinations with replacement. But you can use builtins to generate normal combinations, permutations, tuples, etc.

This is code-golf, shortest code wins.

Example
Input: 4 2
Output: [0 0] [0 1] [0 2] [0 3] [1 1] [1 2] [1 3] [2 2] [2 3] [3 3]

"""

from itertools import combinations_with_replacement

def gen(n, k):
    return list(combinations_with_replacement(range(n), k))

def main():
    assert(gen(4, 2) == [(0, 0), (0, 1), (0, 2), (0, 3), (1, 1), (1, 2), (1, 3), (2, 2), (2, 3), (3, 3)])

main()


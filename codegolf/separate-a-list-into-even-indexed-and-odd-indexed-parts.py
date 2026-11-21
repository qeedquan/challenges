#!/usr/bin/env python3

"""

Inspired by this question:

Make a function (or a full program) that receives a list of numbers and outputs the list rearranged, so that even-indexed numbers appear first, and odd-indexed numbers follow. The values of the numbers themselves don't affect ordering - only their indices do. All indices are zero-based.

For example:

Input: [0, 1, 2, 3, 4]

Output: [0, 2, 4, 1, 3]

Another example:

Input: [110, 22, 3330, 4444, 55555, 6]

Output: [110, 3330, 55555, 22, 4444, 6]

Use most natural representation for lists that your language has. There are no limitations on complexity (e.g. allocating a temporary list is OK - no need to do it in-place).

P.S. It should work for the empty list (empty input => empty output).

"""

def sort(a):
    return a[::2] + a[1::2]

def main():
    assert(sort([0, 1, 2, 3, 4]) == [0, 2, 4, 1, 3])
    assert(sort([110, 22, 3330, 4444, 55555, 6]) == [110, 3330, 55555, 22, 4444, 6])

main()

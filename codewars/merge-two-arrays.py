#!/usr/bin/env python3

"""

Write a function that combines two arrays by alternatingly taking elements from each array in turn.

Examples:

[a, b, c, d, e], [1, 2, 3, 4, 5] becomes  [a, 1, b, 2, c, 3, d, 4, e, 5]

[1, 2, 3], [a, b, c, d, e, f] becomes [1, a, 2, b, 3, c, d, e, f]

Points:

The arrays may be of different lengths, with at least one character/digit.
One array will be of string characters (in lower case, a-z), a second of integers (all positive starting at 1).

Inspired by https://adriann.github.io/programming_problems.html

"""

def merge(a, b):
    r = []
    n = max(len(a), len(b))
    for i in range(n):
        if i < len(a):
            r.append(a[i])
        if i < len(b):
            r.append(b[i])
    return r

def main():
    assert(merge(['a', 'b', 'c', 'd', 'e'], [1, 2, 3, 4, 5]) == ['a', 1, 'b', 2, 'c', 3, 'd', 4, 'e', 5])
    assert(merge([1, 2, 3], ['a', 'b', 'c', 'd', 'e', 'f']) == [1, 'a', 2, 'b', 3, 'c', 'd', 'e', 'f'])

main()


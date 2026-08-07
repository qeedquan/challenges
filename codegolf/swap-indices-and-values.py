#!/usr/bin/env python3

"""

The task
Write a program or function whose input is a list/array X of integers, and whose output is a list of sets of integers Y, such that for each element e in each set Y[i], X[e] = i, and such that the total number of elements in the sets in Y equals the number of elements in X.

(This is basically the same operation as reversing a hashtable/dictionary, except applied to arrays instead.)

Examples
These examples assume 1-based indexing, but you can use 0-based indexing instead if you prefer.

X             Y
[4]           [{},{},{},{1}]
[1,2,3]       [{1},{2},{3}]
[2,2,2]       [{},{1,2,3}]
[5,5,6,6]     [{},{},{},{},{1,2},{3,4}]
[6,6,5,5]     [{},{},{},{},{3,4},{1,2}]

Clarifications
You may represent a set as a list, if you wish. If you do so, the order of its elements does not matter, but you may not repeat elements.
You can use any reasonable unambiguous I/O format; for example, you could separate elements of a set with spaces, and the sets themselves with newlines.
Y should be finitely long, and at least long enough to have all elements of X as array indexes. It may, however, be longer than the maximal element of X (the extra elements would be empty sets).
The elements of X will all be valid array indices, i.e. non-negative integers if you use 0-based indexing, or positive integers if you use 1-based indexing.

Victory condition
As a code-golf challenge, shorter is better.

"""

def swiv(a):
    r = [[] for i in range(max(a))]
    for i, j in enumerate(a):
        r[j - 1] += [i + 1]
    return r

def main():
    assert(swiv([4]) == [[], [], [], [1]])
    assert(swiv([1, 2, 3]) == [[1], [2], [3]])
    assert(swiv([2, 2, 2]) == [[], [1, 2, 3]])
    assert(swiv([5, 5, 6, 6]) == [[], [], [], [], [1, 2], [3, 4]])
    assert(swiv([6, 6, 5, 5]) == [[], [], [], [], [3, 4] , [1, 2]])

main()

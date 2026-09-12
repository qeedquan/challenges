#!/usr/bin/env python3

"""

Given a list of Integers greater than zero, Sort each of the unique values in ascending order, then repeat the process on the remaining duplicate values and append.

Example:

[1,5,2,2,8,3,5,2,9] ==> [1,2,3,5,8,9,2,5,2]
[8,5] ==> [5,8]
[2,2,2] ==> [2,2,2]

"""

"""

@Albert.Lang

Straight-forward method used by many other answers previously: Pick, sort and remove uniques and start over.

"""

def itersort(L):
    return [*map(L.remove, x := {*L})] and sorted(x)+itersort(L)

def main():
    assert(itersort([1, 5, 2, 2, 8, 3, 5, 2, 9]) == [1, 2, 3, 5, 8, 9, 2, 5, 2])
    assert(itersort([8, 5]) == [5, 8])
    assert(itersort([2, 2, 2]) == [2, 2, 2])

main()

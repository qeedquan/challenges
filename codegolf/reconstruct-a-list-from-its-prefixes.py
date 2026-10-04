#!/usr/bin/env python3

"""

A list  [a1,a2,a3⋯an] can be uniquely represented as an unordered list of its prefixes -  [[a1],[a1,a2],[a1,a2,a3]⋯[a1,a2,a3⋯an]].
This can be in any order - for example,  [1,2,3] could be represented by any of [[1],[1,2],[1,2,3]], [[3,2,1],[2,1],[1]], or [[2,1],[1],[3,1,2]]; and these are all equivalent up to order and all represent [1,2,3].

Your challenge is, given a (non-empty) list of the prefixes of a list of positive integers in any order, to return the list represented by that. The list may contain repeated items. This is code-golf, shortest wins!

Testcases
Note: the order of the output does matter, e.g. for the third test case you must output [6, 4, 8, 7], not [7, 4, 8, 6].

[[1], [1, 2], [1, 2, 3]] -> [1, 2, 3]
[[2, 1], [1], [3, 1, 2]] -> [1, 2, 3]
[[6, 4, 8], [7, 4, 8, 6], [6, 4], [6]] -> [6, 4, 8, 7]
[[6, 2, 3, 1], [1, 2], [1], [6, 1, 2], [2, 2, 3, 1, 6]] -> [1, 2, 6, 3, 2]
[[2], [30, 2, 27, 40], [27, 40, 2, 89, 30], [2, 30, 27], [27, 2]] -> [2, 27, 30, 40, 89]
[[8, 4], [4, 8, 8, 4], [4, 4, 8], [4]] -> [4, 8, 4, 8]
[[22, 98, 62, 80], [80, 98], [22, 98, 10, 62, 80, 87, 2], [98], [62, 80, 98], [22, 98, 2, 62, 80], [2, 22, 98, 62, 87, 80]] -> [98, 80, 62, 22, 2, 87, 10]
[[43, 84, 56, 19], [56, 43], [43, 56, 19], [43]] -> [43, 56, 19, 84]

"""

"""

Ported from @xnor solution

Take the sums of the input lists, sort them in increasing order, take adjacent differences.
This works because the difference between the sums of two consecutive prefixes is just the added element,
and sorting works because the numbers are positive.

"""

def reconstruct(array):
    result = []
    previous = 0
    for value in sorted(map(sum, array)):
        result.append(value - previous)
        previous = value
    return result

def main():
    assert(reconstruct([[1], [1, 2], [1, 2, 3]]) == [1, 2, 3])
    assert(reconstruct([[2, 1], [1], [3, 1, 2]]) == [1, 2, 3])
    assert(reconstruct([[6, 4, 8], [7, 4, 8, 6], [6, 4], [6]]) == [6, 4, 8, 7])
    assert(reconstruct([[6, 2, 3, 1], [1, 2], [1], [6, 1, 2], [2, 2, 3, 1, 6]]) == [1, 2, 6, 3, 2])
    assert(reconstruct([[2], [30, 2, 27, 40], [27, 40, 2, 89, 30], [2, 30, 27], [27, 2]]) == [2, 27, 30, 40, 89])
    assert(reconstruct([[8, 4], [4, 8, 8, 4], [4, 4, 8], [4]]) == [4, 8, 4, 8])
    assert(reconstruct([[22, 98, 62, 80], [80, 98], [22, 98, 10, 62, 80, 87, 2], [98], [62, 80, 98], [22, 98, 2, 62, 80], [2, 22, 98, 62, 87, 80]]) == [98, 80, 62, 22, 2, 87, 10])
    assert(reconstruct([[43, 84, 56, 19], [56, 43], [43, 56, 19], [43]]) == [43, 56, 19, 84])

main()

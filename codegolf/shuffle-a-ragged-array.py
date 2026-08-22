#!/usr/bin/env python3

"""

A ragged array is an array where each element is an array of unknown number of positive integers.

For example, the following are ragged arrays:

[[1,2,3],[4],[9,10]]               Shape:  3,1,2
[[1],[2],[3]]                      Shape:  1,1,1
[[1,2,3,4,5,6,8]]                  Shape:  7
The following are not ragged arrays:

[1]   Each element will be an array
[]    The array will contain at least 1 element
[[1,2,3],[]]  Each subarray will contain at least 1 integer
You need to input a ragged array, and return a ragged array with the integers shuffled

The output array must have the same shape as the input array. We define the shape of the array as the length of each subarray.
Each integer must have an equally likely chance to appear in each possible location.
You can assume that your language's built-in random is random.
For example, if I passed in: [[4],[1,2,3],[4]], then [[1],[4,4,2],[3]] would be a valid output, but [[4,1,3],[3],[4]] or [[4],[4],[1,2,3]] would not.

"""

from random import *

def ragged_shuffle(array):
    flattened = sum(array, [])
    shuffle(flattened)

    result = []
    for elements in array:
        child = []
        for _ in elements:
            child.append(flattened.pop())
        result.append(child)
    return result

def main():
    print(ragged_shuffle([[1, 2, 3], [4], [9, 10]]))
    print(ragged_shuffle([[1], [2], [3]]))
    print(ragged_shuffle([[1, 2, 3, 4, 5, 6, 8]]))

main()

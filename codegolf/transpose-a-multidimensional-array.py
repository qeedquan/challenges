#!/usr/bin/env python3

"""

Transposition is an operation on 2-dimensional arrays that flips every element across the main diagonal:

[[1,2,3],    [[1,4],
 [4,5,6]] ->  [2,5],
              [3,6]]
If we call the above array m, then the 2 is the second item of the first row of m, or m[0][1]. The 2 can be thought of as having a coordinate of [0, 1] in the array because of this. When the matrix is transposed, the 2 moves to the first item of the second row, or m[1][0], and its coordinate is now [1, 0].

In general, tranposition can be described as taking the coordinate of every item in the array and swapping the first and second item. This can be generalised to higher dimensions by taking the coordinate rotating it left by one item - moving the first item of the coordinate to the end.

This idea of a coordinate extends fairly easily to arrays of higher dimensions. For example, with the array z = [[[1, 2], [3, 4]], [[5, 6], [7, 8]]], the 6 is z[1][0][1], and its coordinate is [1, 0, 1].

If we apply the same idea of transposition to this coordinate, the coordinate of 6 [1, 0, 1] is shifted left by one item to result in [0, 1, 1], meaning it is now z[0][1][1]. Similarly, the 2 with coordinate [0, 0, 1] is rotated left to result in [0, 1, 0]If we apply this operation to every element of the array, we get [[[1, 5], [2, 6]], [[3, 7], [4, 8]]].

Your challenge is to apply this transformation to a multidimensional rectangular array of positive integers.

You may additionally take the dimensions of the array.

Testcases
[[1]] -> [[1]]
[[[[1, 2]]]] -> [[[[1], [2]]]]
[[1, 2, 3], [4, 5, 6]] -> [[1, 4], [2, 5], [3, 6]]
[[[1, 2], [3, 4]], [[5, 6], [7, 8]]] -> [[[1, 5], [2, 6]], [[3, 7], [4, 8]]]
[[[[9]], [[10]]]] -> [[[[9]]], [[[10]]]]
[[[1, 2, 3], [4, 5, 6]], [[7, 8, 9], [10, 11, 12]]] -> [[[1, 7], [2, 8], [3, 9]], [[4, 10], [5, 11], [6, 12]]]

"""

import numpy as np

def solve(array, dimension):
    return array.transpose(range(1 - dimension, 1))

def main():
    arrays = [
        [[1]],
        [[[[1, 2]]]],
        [[1, 2, 3], [4, 5, 6]],
        [[[1, 2], [3, 4]], [[5, 6], [7, 8]]],
        [[[[9]], [[10]]]],
        [[[1, 2, 3], [4, 5, 6]], [[7, 8, 9], [10, 11, 12]]],
    ]
    for array in arrays:
        array = np.array(array)
        print(solve(array, array.ndim))

main()

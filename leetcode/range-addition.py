#!/usr/bin/env python3

"""

Question
Assume you have an array of length n initialized with all 0’s and are given k update operations.

Each operation is represented as a triplet: [startIndex, endIndex, inc] which increments each element of subarray A[startIndex … endIndex] (startIndex and endIndex inclusive) with inc.

Return the modified array after all k operations were executed.

Example:

Given:

    length = 5,
    updates = [
        [1,  3,  2],
        [2,  4,  3],
        [0,  2, -2]
    ]

Output:

    [-2, 0, 3, 5, 3]
Explanation:

Initial state:
[ 0, 0, 0, 0, 0 ]

After applying operation [1, 3, 2]:
[ 0, 2, 2, 2, 0 ]

After applying operation [2, 4, 3]:
[ 0, 2, 5, 5, 3 ]

After applying operation [0, 2, -2]:
[-2, 0, 3, 5, 3 ]

"""

def modified(length, updates):
    array = [0] * length
    for start, end, val in updates:
        array[start] += val
        if end+1 < length:
            array[end+1] -= val
    
    prefix = 0
    for i in range(length):
        prefix += array[i]
        array[i] = prefix

    return array

def main():
    assert(modified(5, [[1, 3, 2], [2, 4, 3], [0, 2, -2]]) == [-2, 0, 3, 5, 3])

main()

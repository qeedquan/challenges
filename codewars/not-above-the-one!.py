#!/usr/bin/env python3

"""

Task
Implement a function which finds the numbers less than 2, and the indices of numbers greater than 1 in the given sequence, and returns them as a pair of sequences.

Return a nested array or a tuple depending on the language:

The first sequence being only the 1s and 0s from the original sequence.
The second sequence being the indexes of the elements greater than 1 in the original sequence.

Examples
[ 0, 1, 2, 1, 5, 6, 2, 1, 1, 0 ] => [ [ 0, 1, 1, 1, 1, 0 ], [ 2, 4, 5, 6 ] ]

"""

def binary_cleaner(array):
    result = [[], []]
    index = 0
    for value in array:
        if value < 2:
            result[0].append(value)
        else:
            result[1].append(index)
        index += 1
    return result

def main():
    assert(binary_cleaner([0, 1, 2, 1, 5, 6, 2, 1, 1, 0]) == [[0, 1, 1, 1, 1, 0], [2, 4, 5, 6]])

main()

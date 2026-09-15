#!/usr/bin/env python3

"""

In this Kata, you will sort elements in an array by decreasing frequency of elements. If two elements have the same frequency, sort them by increasing value.

solve([2,3,5,3,7,9,5,3,7]) = [3,3,3,5,5,7,7,2,9]
--we sort by highest frequency to lowest frequency. If two elements have same frequency, we sort by increasing value
More examples in test cases.

Good luck!

"""

from functools import cmp_to_key

def freqsort(array):
    histogram = {}
    for value in array:
        if value not in histogram:
            histogram[value] = 0
        histogram[value] += 1
    
    def cmp(value0, value1):
        if histogram[value1] == histogram[value0]:
            return value0 - value1
        return histogram[value1] - histogram[value0]

    return sorted(array, key=cmp_to_key(cmp))

def main():
    assert(freqsort([2, 3, 5, 3, 7, 9, 5, 3, 7]) == [3, 3, 3, 5, 5, 7, 7, 2, 9])

main()


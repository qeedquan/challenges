#!/usr/bin/env python3

"""

Given an integer array arr, return the number of distinct bitwise ORs of all the non-empty subarrays of arr.

The bitwise OR of a subarray is the bitwise OR of each integer in the subarray. The bitwise OR of a subarray of one integer is that integer.

A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:
Input: arr = [0]
Output: 1
Explanation: There is only one possible result: 0.

Example 2:
Input: arr = [1,1,2]
Output: 3
Explanation: The possible subarrays are [1], [1], [2], [1, 1], [1, 2], [1, 1, 2].
These yield the results 1, 1, 2, 1, 3, 3.
There are 3 unique values, so the answer is 3.

Example 3:
Input: arr = [1,2,4]
Output: 6
Explanation: The possible results are 1, 2, 3, 4, 6, and 7.

Constraints:

1 <= arr.length <= 5 * 10^4
0 <= arr[i] <= 10^9

"""

def subarray_bitwise_ors(a):
    r, c = set(), {0}
    for i in a:
        c = {i} | {i | j for j in c}
        r |= c
    return len(r)

def main():
    assert(subarray_bitwise_ors([0]) == 1)
    assert(subarray_bitwise_ors([1, 1, 2]) == 3)
    assert(subarray_bitwise_ors([1, 2, 4]) == 6)

main()

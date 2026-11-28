#!/usr/bin/env python3

"""

You are given an integer array nums. The unique elements of an array are the elements that appear exactly once in the array.

Return the sum of all the unique elements of nums.

Example 1:

Input: nums = [1,2,3,2]
Output: 4
Explanation: The unique elements are [1,3], and the sum is 4.
Example 2:

Input: nums = [1,1,1,1,1]
Output: 0
Explanation: There are no unique elements, and the sum is 0.
Example 3:

Input: nums = [1,2,3,4,5]
Output: 15
Explanation: The unique elements are [1,2,3,4,5], and the sum is 15.


Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100

"""

def sum_of_unique(a):
    m = {}
    for v in a:
        if v not in m:
            m[v] = 0
        m[v] += 1
    
    r = 0
    for k in m:
        if m[k] == 1:
            r += k
    return r

def main():
    assert(sum_of_unique([1, 2, 3, 2]) == 4)
    assert(sum_of_unique([1, 1, 1, 1, 1]) == 0)
    assert(sum_of_unique([1, 2, 3, 4, 5]) == 15)

main()

#!/usr/bin/env python3

"""

Given an integer array nums, return the most frequent even element.

If there is a tie, return the smallest one. If there is no such element, return -1.

Example 1:

Input: nums = [0,1,2,2,4,4,1]
Output: 2
Explanation:
The even elements are 0, 2, and 4. Of these, 2 and 4 appear the most.
We return the smallest one, which is 2.

Example 2:

Input: nums = [4,4,4,9,2,4]
Output: 4
Explanation: 4 is the even element appears the most.

Example 3:

Input: nums = [29,47,21,41,13,37,25,7]
Output: -1
Explanation: There is no even element.

Constraints:

    1 <= nums.length <= 2000
    0 <= nums[i] <= 10^5

"""

def frequent(a):
    m = {}
    r, c = -1, 0
    for v in a:
        if v&1 != 0:
            continue

        if v not in m:
            m[v] = 0
        m[v] += 1
        
        if c < m[v] or (c == m[v] and r > v):
            r, c = v, m[v]
    return r

def main():
    assert(frequent([0, 1, 2, 2, 4, 4, 1]) == 2)
    assert(frequent([4, 4, 4, 9, 2, 4]) == 4)
    assert(frequent([29, 47, 21, 41, 13, 37, 25, 7]) == -1)
    assert(frequent([0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3]) == 0)

main()

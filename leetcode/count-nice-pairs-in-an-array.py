#!/usr/bin/env python3

"""

You are given an array nums that consists of non-negative integers. Let us define rev(x) as the reverse of the non-negative integer x. For example, rev(123) = 321, and rev(120) = 21. A pair of indices (i, j) is nice if it satisfies all of the following conditions:

0 <= i < j < nums.length
nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])
Return the number of nice pairs of indices. Since that number can be too large, return it modulo 109 + 7.



Example 1:

Input: nums = [42,11,1,97]
Output: 2
Explanation: The two pairs are:
 - (0,3) : 42 + rev(97) = 42 + 79 = 121, 97 + rev(42) = 97 + 24 = 121.
 - (1,2) : 11 + rev(1) = 11 + 1 = 12, 1 + rev(11) = 1 + 11 = 12.
Example 2:

Input: nums = [13,10,35,24,76]
Output: 4


Constraints:

1 <= nums.length <= 10^5
0 <= nums[i] <= 10^9

Hint:
The condition can be rearranged to (nums[i] - rev(nums[i])) == (nums[j] - rev(nums[j])).
Transform each nums[i] into (nums[i] - rev(nums[i])). Then, count the number of (i, j) pairs that have equal values.
Keep a map storing the frequencies of values that you have seen so far. For each i, check if nums[i] is in the map. If it is, then add that count to the overall count. Then, increment the frequency of nums[i].

"""

from collections import *

# https://walkccc.me/LeetCode/problems/1814/
def nicepairs(nums):
    freqs = Counter(num - int(str(num)[::-1]) for num in nums)
    return sum(freq * (freq - 1) // 2 for freq in freqs.values()) % 1000000007

def main():
    assert(nicepairs([42, 11, 1, 97]) == 2)
    assert(nicepairs([13, 10, 35, 24, 76]) == 4)

main()

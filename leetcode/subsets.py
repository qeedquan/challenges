#!/usr/bin/env python3

"""

Given an integer array nums of unique elements, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]


Constraints:

1 <= nums.length <= 10
-10 <= nums[i] <= 10
All the numbers of nums are unique.

"""

def recurse(nums, depth, path, result):
    result.append(path)
    for i in range(depth, len(nums)):
        recurse(nums, i + 1, path + [nums[i]], result)

def subsets(nums):
    result = []
    recurse(nums, 0, [], result)
    return result

def test(nums, expected):
    result = subsets(nums)
    print(result)
    assert(sorted(result) == sorted(expected))

def main():
    test([1, 2, 3], [[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]])
    test([0], [[], [0]])

main()

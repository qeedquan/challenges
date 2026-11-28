#!/usr/bin/env python3

"""

You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.

If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.

Return the maximum coins you can collect by bursting the balloons wisely.

Example 1:

Input: nums = [3,1,5,8]
Output: 167
Explanation:
nums = [3,1,5,8] --> [3,5,8] --> [3,8] --> [8] --> []
coins =  3*1*5    +   3*5*8   +  1*3*8  + 1*8*1 = 167

Example 2:

Input: nums = [1,5]
Output: 10


Constraints:

n == nums.length
1 <= n <= 300

"""

def maxcoins(nums):
    n = len(nums)
    A = [1] + nums + [1]
    dp = [[0] * (n+2) for _ in range(n+2)]

    for d in range(n):
        for i in range(1, n-d+1):
            j = i + d
            for k in range(i, j+1):
                dp[i][j] = max(dp[i][j], dp[i][k-1] + dp[k+1][j] + A[i-1]*A[k]*A[j+1])

    return dp[1][n]

def main():
    assert(maxcoins([3, 1, 5, 8]) == 167)
    assert(maxcoins([1, 5]) == 10)

main()

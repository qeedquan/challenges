#!/usr/bin/env python3

"""

Bob is standing at cell (0, 0), and he wants to reach destination: (row, column). He can only travel right and down.
You are going to help Bob by providing instructions for him to reach destination.

The instructions are represented as a string, where each character is either:

'H', meaning move horizontally (go right), or
'V', meaning move vertically (go down).
Multiple instructions will lead Bob to destination. For example, if destination is (2, 3), both "HHHVV" and "HVHVH" are valid instructions.

However, Bob is very picky. Bob has a lucky number k, and he wants the kth lexicographically smallest instructions that will lead him to destination. k is 1-indexed.

Given an integer array destination and an integer k, return the kth lexicographically smallest instructions that will take Bob to destination.

Example 1:
https://assets.leetcode.com/uploads/2020/10/12/ex1.png

Input: destination = [2,3], k = 1
Output: "HHHVV"
Explanation: All the instructions that reach (2, 3) in lexicographic order are as follows:
["HHHVV", "HHVHV", "HHVVH", "HVHHV", "HVHVH", "HVVHH", "VHHHV", "VHHVH", "VHVHH", "VVHHH"].

Example 2:
https://assets.leetcode.com/uploads/2020/10/12/ex2.png
Input: destination = [2,3], k = 2
Output: "HHVHV"

Example 3:
https://assets.leetcode.com/uploads/2020/10/12/ex3.png
Input: destination = [2,3], k = 3
Output: "HHVVH"
 

Constraints:

destination.length == 2
1 <= row, column <= 15
1 <= k <= nCr(row + column, row), where nCr(a, b) denotes a choose b.

Hint 1
There are nCr(row + column, row) possible instructions to reach (row, column).

Hint 2
Try building the instructions one step at a time. How many instructions start with "H", and how does this compare with k?

"""

from math import comb

def kth(d, k):
    s, r, c = "", d[0], d[1]
    while r + c != 0:
        n = comb(r + c - 1, r)
        if k <= n:
            c -= 1
            s += "H"
        else:
            k -= n
            r -= 1
            s += "V"
    return s

def main():
    assert(kth([2, 3], 1) == "HHHVV")
    assert(kth([2, 3], 2) == "HHVHV")
    assert(kth([2, 3], 3) == "HHVVH")

main()


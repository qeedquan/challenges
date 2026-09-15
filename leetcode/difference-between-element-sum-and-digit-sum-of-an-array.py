#!/usr/bin/env python3

"""

You are given a positive integer array nums.

The element sum is the sum of all the elements in nums.
The digit sum is the sum of all the digits (not necessarily distinct) that appear in nums.
Return the absolute difference between the element sum and digit sum of nums.

Note that the absolute difference between two integers x and y is defined as |x - y|.

Example 1:

Input: nums = [1,15,6,3]
Output: 9
Explanation:
The element sum of nums is 1 + 15 + 6 + 3 = 25.
The digit sum of nums is 1 + 1 + 5 + 6 + 3 = 16.
The absolute difference between the element sum and digit sum is |25 - 16| = 9.

Example 2:

Input: nums = [1,2,3,4]
Output: 0
Explanation:
The element sum of nums is 1 + 2 + 3 + 4 = 10.
The digit sum of nums is 1 + 2 + 3 + 4 = 10.
The absolute difference between the element sum and digit sum is |10 - 10| = 0.


Constraints:

1 <= nums.length <= 2000
1 <= nums[i] <= 2000

Hint:
Use a simple for loop to iterate each number.
How you can get the digit for each number?

"""

def digitsum(n):
    r = 0
    while n > 0:
        r += n % 10
        n //= 10
    return r

def diffsum(a):
    x = sum(a)
    y = 0
    for v in a:
        y += digitsum(v)
    return abs(x - y)

def main():
    assert(diffsum([1, 15, 6, 3]) == 9)
    assert(diffsum([1, 2, 3, 4]) == 0)

main()

#!/usr/bin/env python3

"""

There is a function signFunc(x) that returns:

    1 if x is positive.
    -1 if x is negative.
    0 if x is equal to 0.

You are given an integer array nums. Let product be the product of all values in the array nums.

Return signFunc(product).

Example 1:

Input: nums = [-1,-2,-3,-4,3,2,1]
Output: 1
Explanation: The product of all values in the array is 144, and signFunc(144) = 1

Example 2:

Input: nums = [1,5,0,2,-3]
Output: 0
Explanation: The product of all values in the array is 0, and signFunc(0) = 0

Example 3:

Input: nums = [-1,1,-1,1,-1]
Output: -1
Explanation: The product of all values in the array is -1, and signFunc(-1) = -1

Constraints:

    1 <= nums.length <= 1000
    -100 <= nums[i] <= 100

"""

def sign(x):
    if x < 0:
        return -1
    if x == 0:
        return 0
    return 1

def signprod(a):
    if len(a) == 0:
        return 0

    x = sign(a[0])
    for i in range(1, len(a)):
        y = sign(a[i])
        if x == 0 or y == 0:
            return 0
        elif x == y:
            x = 1
        elif x != y:
            x = -1
    return x

def main():
    assert(signprod([-1, -2, -3, -4, 3, 2, 1]) == 1)
    assert(signprod([1, 5, 0, 2, -3]) == 0)
    assert(signprod([-1, 1, -1, 1, -1]) == -1)
    assert(signprod([-1, -100]) == 1)
    
main()

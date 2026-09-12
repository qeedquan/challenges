#!/usr/bin/env python3

"""

Given an array of integers arr, return true if and only if it is a valid mountain array.

Recall that arr is a mountain array if and only if:

arr.length >= 3
There exists some i with 0 < i < arr.length - 1 such that:
arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

Example 1:

Input: arr = [2,1]
Output: false
Example 2:

Input: arr = [3,5,5]
Output: false
Example 3:

Input: arr = [0,3,2,1]
Output: true


Constraints:

1 <= arr.length <= 10^4
0 <= arr[i] <= 10^4

"""

def mountain(a):
    n = len(a)
    if n < 3:
        return False

    i = 0
    while i < n-1:
        if a[i] >= a[i+1]:
            break
        i += 1

    while i < n-1:
        if a[i] <= a[i+1]:
            break
        i += 1

    return i == n-1

def main():
    assert(mountain([2, 1]) == False)
    assert(mountain([3, 5, 5]) == False)
    assert(mountain([0, 3, 2, 1]) == True)
    assert(mountain([0, 2, 3, 4, 5, 2, 1, 0]) == True)
    assert(mountain([0, 2, 3, 3, 5, 2, 1, 0]) == False)

main()

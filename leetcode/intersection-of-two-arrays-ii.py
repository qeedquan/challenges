#!/usr/bin/env python3

"""

Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Explanation: [9,4] is also accepted.


Constraints:

1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 1000


Follow up:

What if the given array is already sorted? How would you optimize your algorithm?
What if nums1's size is small compared to nums2's size? Which algorithm is better?
What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?

"""

def multiset(a):
    m = {}
    for v in a:
        if v not in m:
            m[v] = 0
        m[v] += 1
    return m

def common(x, y):
    z = {}
    for v in x:
        if v in y:
            z[v] = min(x[v], y[v])
    return z

def intersect(a, b):
    return common(multiset(a), multiset(b))

def main():
    assert(intersect([1, 2, 2, 1], [2, 2]) == multiset([2, 2]))
    assert(intersect([4, 9, 5], [9, 4, 9, 8, 4]) == multiset([4, 9]))

main()

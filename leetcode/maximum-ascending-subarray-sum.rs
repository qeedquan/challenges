/*

Given an array of positive integers nums, return the maximum possible sum of an strictly increasing subarray in nums.

A subarray is defined as a contiguous sequence of numbers in an array.

Example 1:
Input: nums = [10,20,30,5,10,50]
Output: 65
Explanation: [5,10,50] is the ascending subarray with the maximum sum of 65.

Example 2:
Input: nums = [10,20,30,40,50]
Output: 150
Explanation: [10,20,30,40,50] is the ascending subarray with the maximum sum of 150.

Example 3:
Input: nums = [12,17,15,13,10,11,12]
Output: 33
Explanation: [10,11,12] is the ascending subarray with the maximum sum of 33.

Constraints:

1 <= nums.length <= 100
1 <= nums[i] <= 100

*/

use std::cmp::max;

fn main() {
    assert_eq!(max_ascending_sum(&[10, 20, 30, 5, 10, 50]), 65);
    assert_eq!(max_ascending_sum(&[10, 20, 30, 40, 50]), 150);
    assert_eq!(max_ascending_sum(&[12, 17, 15, 13, 10, 11, 12]), 33);
    assert_eq!(max_ascending_sum(&[100, 10, 1]), 100);
}

fn max_ascending_sum(a: &[isize]) -> isize {
    if a.len() == 0 {
        return 0;
    }

    let mut m = a[0];
    let mut s = a[0];
    for i in 1..a.len() {
        if a[i] > a[i - 1] {
            s += a[i];
        } else {
            m = max(m, s);
            s = a[i];
        }
    }
    max(m, s)
}

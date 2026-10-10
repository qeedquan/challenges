/*

Given a binary array nums, return the maximum number of consecutive 1's in the array.

Example 1:

Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.
Example 2:

Input: nums = [1,0,1,1,0,1]
Output: 2
 

Constraints:

1 <= nums.length <= 10^5
nums[i] is either 0 or 1.

*/

use std::cmp::max;

fn main() {
    assert_eq!(max_consecutive_ones(vec![1, 1, 0, 1, 1, 1]), 3);
    assert_eq!(max_consecutive_ones(vec![1, 0, 1, 1, 0, 1]), 2);
}

fn max_consecutive_ones(a: Vec<isize>) -> usize {
    let (mut r, mut i, n) = (0, 0, a.len());
    while i < n {
        let mut j = i;
        while j < n && a[i] == a[j] {
            j += 1;
        }
        if a[i] == 1 {
            r = max(r, j - i);
        }
        i = j;
    }
    r
}

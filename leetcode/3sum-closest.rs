/*

Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.

Example 1:

Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
Example 2:

Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).
 

Constraints:

3 <= nums.length <= 500
-1000 <= nums[i] <= 1000
-10^4 <= target <= 10^4

*/

fn main() {
    assert_eq!(three_sum_closest(vec![-1, 2, 1, -4], 1), 2);
    assert_eq!(three_sum_closest(vec![0, 0, 0], 1), 0);
}

fn three_sum_closest(a: Vec<isize>, t: isize) -> isize {
    let (mut r, mut m, n) = (0, isize::MAX, a.len());
    for i in 0..n {
        for j in i + 1..n {
            for k in j + 1..n {
                let v = a[i] + a[j] + a[k];
                let d = (t - v).abs();
                if d < m {
                    (r, m) = (v, d);
                }
            }
        }
    }
    r
}

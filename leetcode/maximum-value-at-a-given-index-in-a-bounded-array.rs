/*

You are given three positive integers: n, index, and maxSum. You want to construct an array nums (0-indexed) that satisfies the following conditions:

nums.length == n
nums[i] is a positive integer where 0 <= i < n.
abs(nums[i] - nums[i+1]) <= 1 where 0 <= i < n-1.
The sum of all the elements of nums does not exceed maxSum.
nums[index] is maximized.
Return nums[index] of the constructed array.

Note that abs(x) equals x if x >= 0, and -x otherwise.

Example 1:

Input: n = 4, index = 2,  maxSum = 6
Output: 2
Explanation: nums = [1,2,2,1] is one array that satisfies all the conditions.
There are no arrays that satisfy all the conditions and have nums[2] == 3, so 2 is the maximum nums[2].

Example 2:

Input: n = 6, index = 1,  maxSum = 10
Output: 3

Constraints:

1 <= n <= maxSum <= 10^9
0 <= index < n

*/

fn main() {
    assert_eq!(solve(4, 2, 6), 2);
    assert_eq!(solve(6, 1, 10), 3);
}

fn solve(n: isize, index: isize, mut max_sum: isize) -> isize {
    if !(1 <= n && n <= max_sum) {
        return 0;
    }
    if !(0 <= index && index < n) {
        return 0;
    }

    let mut max_value = 1;
    let mut layer = 1;

    max_sum -= n;
    while max_sum > 0 {
        let mut points = (2 * layer) - 1;

        let right = (index + layer - 1) - (n - 1);
        if right > 0 {
            points -= right;
        }

        let left = layer - index - 1;
        if left > 0 {
            points -= left;
        }

        if points >= n || max_sum < points {
            break;
        }

        max_sum -= points;
        layer += 1;
        max_value += 1;
    }
    max_value += max_sum / n;

    return max_value;
}

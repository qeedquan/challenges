/*

Description
Given an array nums of length n, return an array answer of length n - 1 such that answer[i] = nums[i] | nums[i + 1] where | is the bitwise OR operation.

Example 1:

Input: nums = [1,3,7,15]

Output: [3,7,15]

Example 2:

Input: nums = [8,4,2]

Output: [12,6]

Example 3:

Input: nums = [5,4,9,11]

Output: [5,13,11]

Constraints:

2 <= nums.length <= 100
0 <= nums[i] <= 100

*/

fn main() {
    assert_eq!(ora(&[1, 3, 7, 15]), vec![3, 7, 15]);
    assert_eq!(ora(&[8, 4, 2]), vec![12, 6]);
    assert_eq!(ora(&[5, 4, 9, 11]), vec![5, 13, 11]);
}

fn ora(a: &[isize]) -> Vec<isize> {
    let mut r = vec![];
    let n = a.len();
    if n == 0 {
        return r;
    }

    for i in 0..n - 1 {
        r.push(a[i] | a[i + 1]);
    }
    return r;
}

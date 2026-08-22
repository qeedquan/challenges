/*

You are given an integer array nums containing positive integers.
We define a function encrypt such that encrypt(x) replaces every digit in x with the largest digit in x.
For example, encrypt(523) = 555 and encrypt(213) = 333.

Return the sum of encrypted elements.

Example 1:

Input: nums = [1,2,3]

Output: 6

Explanation: The encrypted elements are [1,2,3]. The sum of encrypted elements is 1 + 2 + 3 == 6.

Example 2:

Input: nums = [10,21,31]

Output: 66

Explanation: The encrypted elements are [11,22,33]. The sum of encrypted elements is 11 + 22 + 33 == 66.

Constraints:

1 <= nums.length <= 50
1 <= nums[i] <= 1000

*/

use std::cmp::max;

fn main() {
    assert_eq!(sum_of_encrypted_int(&[1, 2, 3]), 6);
    assert_eq!(sum_of_encrypted_int(&[10, 21, 31]), 66);
    assert_eq!(sum_of_encrypted_int(&[523]), 555);
    assert_eq!(sum_of_encrypted_int(&[213]), 333);
}

fn sum_of_encrypted_int(numbers: &[usize]) -> usize {
    let mut sum = 0;
    for &number in numbers {
        sum += encrypt(number);
    }
    sum
}

fn encrypt(mut number: usize) -> usize {
    let mut digit = 0;
    let mut length = 0;
    while number > 0 {
        digit = max(digit, number % 10);
        number /= 10;
        length += 1;
    }

    let mut result = 0;
    for _ in 0..length {
        result = (result * 10) + digit;
    }
    result
}

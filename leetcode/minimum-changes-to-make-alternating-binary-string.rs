/*

You are given a string s consisting only of the characters '0' and '1'. In one operation, you can change any '0' to '1' or vice versa.

The string is called alternating if no two adjacent characters are equal. For example, the string "010" is alternating, while the string "0100" is not.

Return the minimum number of operations needed to make s alternating.

Example 1:
Input: s = "0100"
Output: 1
Explanation: If you change the last character to '1', s will be "0101", which is alternating.

Example 2:
Input: s = "10"
Output: 0
Explanation: s is already alternating.

Example 3:
Input: s = "1111"
Output: 2
Explanation: You need two operations to reach "0101" or "1010".

Constraints:

1 <= s.length <= 10^4
s[i] is either '0' or '1'.

*/

use std::cmp::min;

fn main() {
    assert_eq!(minimum_operations("0100"), 1);
    assert_eq!(minimum_operations("10"), 0);
    assert_eq!(minimum_operations("1111"), 2);
}

fn minimum_operations(input: &'static str) -> usize {
    let (mut zero, mut one, mut index) = (0, 0, 0);
    for symbol in input.chars() {
        if index == 0 {
            increment(symbol == '1', &mut zero, &mut one);
        } else {
            increment(symbol == '0', &mut zero, &mut one);
        }
        index ^= 1;
    }
    min(zero, one)
}

fn increment(cond: bool, zero: &mut usize, one: &mut usize) {
    if cond {
        *zero += 1;
    } else {
        *one += 1;
    }
}

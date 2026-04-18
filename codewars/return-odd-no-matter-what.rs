/*

Given the integer n return odd numbers as they are, but subtract 1 from even numbers.

Note:

Your solution should be 36 or less characters long.

Examples
Input  = 2
Output = 1

Input  = 13
Output = 13

Input  = 46
Output = 45

*/

fn main() {
    assert_eq!(always_odd(2), 1);
    assert_eq!(always_odd(13), 13);
    assert_eq!(always_odd(46), 45);
}

fn always_odd(n: isize) -> isize {
    n - ((n & 1) ^ 1)
}

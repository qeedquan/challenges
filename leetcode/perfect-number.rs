/*

A perfect number is a positive integer that is equal to the sum of its positive divisors, excluding the number itself. A divisor of an integer x is an integer that can divide x evenly.

Given an integer n, return true if n is a perfect number, otherwise return false.

Example 1:

Input: num = 28
Output: true
Explanation: 28 = 1 + 2 + 4 + 7 + 14
1, 2, 4, 7, and 14 are all divisors of 28.
Example 2:

Input: num = 7
Output: false


Constraints:

1 <= num <= 10^8

*/

fn main() {
    assert_eq!(perfect(28), true);
    assert_eq!(perfect(7), false);
    assert_eq!(perfect(100000000), false);
}

// https://oeis.org/A000396
fn perfect(n: isize) -> bool {
    let mut r = 0;
    for i in 1..n {
        if r > n {
            break;
        }
        if n % i == 0 {
            r += i;
        }
    }
    r > 0 && r == n
}

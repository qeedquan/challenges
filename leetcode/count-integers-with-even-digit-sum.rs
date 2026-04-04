/*

Given a positive integer num, return the number of positive integers less than or equal to num whose digit sums are even.

The digit sum of a positive integer is the sum of all its digits.

Example 1:

Input: num = 4
Output: 2
Explanation:
The only integers less than or equal to 4 whose digit sums are even are 2 and 4.    
Example 2:

Input: num = 30
Output: 14
Explanation:
The 14 integers less than or equal to 30 whose digit sums are even are
2, 4, 6, 8, 11, 13, 15, 17, 19, 20, 22, 24, 26, and 28.
 

Constraints:

1 <= num <= 1000

*/

fn main() {
    assert_eq!(evens(4), 2);
    assert_eq!(evens(30), 14);
}

fn evens(n: usize) -> usize {
    let mut c = 0;
    for i in 2..n + 1 {
        if digitsum(i) & 1 == 0 {
            c += 1;
        }
    }
    c
}

fn digitsum(mut n: usize) -> usize {
    let mut r = 0;
    while n > 0 {
        r += n % 10;
        n /= 10;
    }
    r
}

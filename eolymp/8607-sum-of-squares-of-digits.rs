/*

A four-digit positive integer n (1000≤n≤9999) is given. Find the sum of the squares of its digits.

Input
A single four-digit positive integer n (1000≤n≤9999).

Output
Print the sum of the squares of the digits of the number n.

Examples
Input #1
1234

Answer #1
30

*/

fn main() {
    assert_eq!(solve(1234), 30);
}

fn solve(mut n: usize) -> usize {
    let mut r = 0;
    while n > 0 {
        let d = n % 10;
        r += d * d;
        n /= 10;
    }
    r
}

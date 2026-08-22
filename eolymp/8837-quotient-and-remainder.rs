/*

Two positive integers a and b are given. Print the quotient and the remainder of dividing a by b.

Input
Two positive integers a and b (a, b≤10^9).

Output
Print the quotient and the remainder of dividing a by b.

Examples

Input #1
27 10

Answer #1
2 7

*/

fn main() {
    assert_eq!(solve(27, 10), (2, 7));
}

fn solve(a: isize, b: isize) -> (isize, isize) {
    (a / b, a % b)
}

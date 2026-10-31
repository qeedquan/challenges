/*

Find the number of N-digit numbers such that the sum of their digits is equal to the product of their digits.
Also, output the smallest such number for the given N, where 1≤N<10.

Input
The number N (1≤N<10).

Output
Output two numbers: the quantity of such N-digit numbers, and the smallest among them, separated by a space.

Examples

Input #1
1

Answer #1
10 0

*/

fn main() {
    assert_eq!(solve(1), (10, 0));
}

// https://oeis.org/A061672
fn solve(n: isize) -> (isize, isize) {
    match n {
        1 => (10, 0),
        2 => (1, 22),
        3 => (6, 123),
        4 => (12, 1124),
        5 => (40, 11125),
        6 => (30, 111126),
        7 => (84, 1111127),
        8 => (224, 11111128),
        9 => (144, 111111129),
        _ => (-1, -1),
    }
}

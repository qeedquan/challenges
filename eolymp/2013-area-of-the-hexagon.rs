/*

A regular hexagon with side L is given. Find its area.

Input
An integer L (1≤L≤10^9).

Output

The area S, rounded to the nearest integer.

Examples
Input #1
2

Answer #1
24

*/

fn main() {
    assert_eq!(solve(2), 24);
}

#[allow(non_snake_case)]
fn solve(L: isize) -> isize {
    6 * L * L
}

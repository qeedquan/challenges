/*

Given the length of a diagonal of a square. Find the length of the side of this square.

Input
The length of a diagonal d (1≤d≤10^18).

Output
Print the length of the side of a square.

Examples

Input #1
2

Answer #1
1.41421356237309

*/

fn main() {
    println!("{}", solve(2.0));
}

fn solve(d: f64) -> f64 {
    d / 2f64.sqrt()
}

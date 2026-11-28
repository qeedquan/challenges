/*

Three real numbers are given. Find their pairwise sums.

Input
Three real numbers x,y,z.

Output
Print in one line the sums x+y,x+z and y+z with 4 decimal digits.

Examples

Input #1
1.2345 3.4566 -0.1236

Answer #1
4.6911 1.1109 3.3330

*/

fn main() {
    println!("{:?}", solve(1.2345, 3.4566, -0.1236));
}

fn solve(x: f64, y: f64, z: f64) -> (f64, f64, f64) {
    (x + y, x + z, y + z)
}

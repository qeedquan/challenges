/*

Find the coefficients in the general equation of a line.

Input
Four numbers are given: the coordinates of a point on the line and the coordinates of a vector normal to this line.
All coordinates are integers with absolute values not exceeding 10000.

Output
Output three integers: the coefficients A, B, and C in the general equation of this line.

Examples

Input #1
1 2 3 1

Answer #1
3 1 -5

*/

fn main() {
    assert_eq!(solve(1, 2, 3, 1), (3, 1, -5));
}

fn solve(x: isize, y: isize, m: isize, n: isize) -> (isize, isize, isize) {
    (m, n, (-m * x) - (n * y))
}

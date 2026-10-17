/*

Find the coefficients of the general equation of a line.

Input
Four integers are given: the coordinates of two distinct points on a line. All input values are integers whose absolute values do not exceed 10000.

Output
Output three integers: the coefficients A, B, and C of the general equation of this line.

Examples
Input #1
1 2 3 1

Answer #1
-1 -2 5

*/

fn main() {
    assert_eq!(solve(1, 2, 3, 1), (-1, -2, 5));
}

fn solve(x1: isize, y1: isize, x2: isize, y2: isize) -> (isize, isize, isize) {
    let a = y2 - y1;
    let b = x1 - x2;
    let c = (y1 * x2) - (y2 * x1);
    (a, b, c)
}

/*

Does the point O belong to the triangle ABC? A point is considered to belong to the triangle if it lies inside it or on its boundary.

Input
The coordinates of the points O, A, B, and C are given. All coordinates are integers whose absolute values do not exceed 100.

Output
Print 1 if the point O belongs to the triangle ABC, and 0 otherwise.

Examples

Input #1
1 1 -1 0 2 4 4 1

Answer #1
1

Input #5
-2 0 7 0 -2 5 0 -5

Answer #5
0

*/

fn main() {
    assert_eq!(solve(1, 1, -1, 0, 2, 4, 4, 1), 1);
    assert_eq!(solve(-2, 0, 7, 0, -2, 5, 0, -5), 0);
}

fn solve(
    a1: isize,
    b1: isize,
    x1: isize,
    y1: isize,
    x2: isize,
    y2: isize,
    x3: isize,
    y3: isize,
) -> isize {
    let s = ((x1 * y2) - (x2 * y1) + (x2 * y3) - (x3 * y2) + (x3 * y1) - (x1 * y3)).abs();
    let s1 = ((x1 * b1) - (a1 * y1) + (a1 * y2) - (b1 * x2) + (x2 * y1) - (x1 * y2)).abs();
    let s2 = ((a1 * y2) - (x2 * b1) + (x2 * y3) - (x3 * y2) + (x3 * b1) - (a1 * y3)).abs();
    let s3 = ((x1 * b1) - (a1 * y1) + (a1 * y3) - (x3 * b1) + (x3 * y1) - (y3 * x1)).abs();
    if s == s1 + s2 + s3 {
        return 1;
    }
    return 0;
}

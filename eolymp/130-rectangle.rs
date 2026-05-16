/*

Given the coordinates of three vertices of a rectangle, find the coordinates of the fourth vertex.

Input
The input consists of a single line containing six integers: x1, y1, x2, y2, x3, y3 — these are the coordinates of three vertices of the rectangle.

All input values are integers with absolute value not exceeding 100.

Output
Output two integers — the coordinates of the missing vertex of the rectangle.

All output values must be integers with absolute value not exceeding 100.

Examples

Input #1
0 0 0 1 2 1

Answer #1
2 0

*/

fn main() {
    assert_eq!(solve(0, 0, 0, 1, 2, 1), (2, 0));
}

fn solve(x1: isize, y1: isize, x2: isize, y2: isize, x3: isize, y3: isize) -> (isize, isize) {
    let d1 = dist2(x1, y1, x2, y2);
    let d2 = dist2(x2, y2, x3, y3);
    let d3 = dist2(x1, y1, x3, y3);

    let (mut x4, mut y4) = (0, 0);
    if d1 > d2 && d1 > d3 {
        x4 = x1 + x2 - x3;
        y4 = y1 + y2 - y3;
    } else if d2 > d1 && d2 > d3 {
        x4 = x2 + x3 - x1;
        y4 = y2 + y3 - y1
    } else if d3 > d1 && d3 > d2 {
        x4 = x1 + x3 - x2;
        y4 = y1 + y3 - y2;
    }
    (x4, y4)
}

fn dist2(x1: isize, y1: isize, x2: isize, y2: isize) -> isize {
    let dx = x2 - x1;
    let dy = y2 - y1;
    (dx * dx) + (dy * dy)
}

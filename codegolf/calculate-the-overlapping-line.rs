/*

(l, r) defines a line whose left end is at l and the right end is at r, on a 1-dimensional space.

Given 2 lines b = (0, bz) and f = (i, i + fz), v = (l, r) is the overlapping part of these lines. When b and f do not overlap (when v cannot have a positive length), v = (0, 0).

(input)   -> (output)
bz, fz, i -> l, r
The data type (int, float, string, etc.) for each value should be able to represent all integers from -128 to 127, inclusive.

You can change the order of input and output variables.

Examples
0, 0, 0 -> 0, 0
1, 1, 1 -> 0, 0
1, 2, 3 -> 0, 0
1, 2, -3 -> 0, 0
2, 1, 1 -> 1, 2
4, 2, 1 -> 1, 3
2, 2, -1 -> 0, 1
2, 4, -1 -> 0, 2

*/

use std::cmp::*;

fn main() {
    assert_eq!(overlap(0, 0, 0), (0, 0));
    assert_eq!(overlap(1, 1, 1), (0, 0));
    assert_eq!(overlap(1, 2, 3), (0, 0));
    assert_eq!(overlap(1, 2, -3), (0, 0));
    assert_eq!(overlap(2, 1, 1), (1, 2));
    assert_eq!(overlap(4, 2, 1), (1, 3));
    assert_eq!(overlap(2, 2, -1), (0, 1));
    assert_eq!(overlap(2, 2, -1), (0, 1));
    assert_eq!(overlap(2, 4, -1), (0, 2));
    assert_eq!(overlap(5, 10, 20), (0, 0));
    assert_eq!(overlap(15, 5, 10), (10, 15));
}

/*

@ophact

Explanation
The overlapping line starts from the beginning of the second line (measured by starting point) because it cannot start from the beginning of the first line (unless both lines start at the same point) because then the beginning would not be part of the second line, and it cannot start at the end of any line because it would leave the line directly afterward.

It ends at the first endpoint, where it first "leaves" a line.

If the start is not less than the end (as found according to the above), then the lines do not overlap, and we can then return [0, 0].

*/

fn overlap(a: isize, b: isize, c: isize) -> (isize, isize) {
    let (mut d, mut e) = (0, min(a, c + b));
    if c > 0 {
        d = c;
    }
    if d >= e {
        (d, e) = (0, 0);
    }
    (d, e)
}

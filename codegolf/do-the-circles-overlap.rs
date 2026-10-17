/*

Given the coordinates of the centres and the radii of 2 circles, output a truthy value of whether they do or do not overlap.

Input
Input may be taken via STDIN or equivalent, function arguments, but not as a variable. You can take them as a single variable (list, string etc) or as multiple inputs / arguments, in whatever order you want.

The input will be six floats. These floats will be up to 3 decimal places. The coordinates can be positive or negative. The radii will be positive.

Output
Output can be via STDOUT or function return.

The program must have exactly 2 distinct outputs - one for a True value (the circles do overlap) and one for a False output (they don't overlap).

Test cases
(Input is given as list of tuples [(x1, y1, r1), (x2, y2, r2)] for the test cases; you can take input in any format)

True
[(5.86, 3.92, 1.670), (11.8, 2.98, 4.571)]
[(8.26, -2.72, 2.488), (4.59, -2.97, 1.345)]
[(9.32, -7.77, 2.8), (6.21, -8.51, 0.4)]
False
[(4.59, -2.97, 1.345), (11.8, 2.98, 4.571)]
[(9.32, -7.77, 2.8), (4.59, -2.97, 1.345)]
[(5.86, 3.92, 1.670), (6.21, -8.51, 0.4)]

This is Code Golf, shortest answer in bytes wins.

*/

fn main() {
    assert_eq!(overlaps(5.86, 3.92, 1.670, 11.8, 2.98, 4.571), true);
    assert_eq!(overlaps(8.26, -2.72, 2.488, 4.59, -2.97, 1.345), true);
    assert_eq!(overlaps(9.32, -7.77, 2.8, 6.21, -8.51, 0.4), true);

    assert_eq!(overlaps(4.59, -2.97, 1.345, 11.8, 2.98, 4.571), false);
    assert_eq!(overlaps(9.32, -7.77, 2.8, 4.59, -2.97, 1.345), false);
    assert_eq!(overlaps(5.86, 3.92, 1.670, 6.21, -8.51, 0.4), false);
}

fn overlaps(x1: f64, y1: f64, r1: f64, x2: f64, y2: f64, r2: f64) -> bool {
    f64::hypot(x1 - x2, y1 - y2) < (r1 + r2)
}

// A point with coordinates x and y is given. Determine in which coordinate quadrant it is located.
//
// Input
// A single line contains 2 real numbers — the coordinates of the point, separated by a space. The absolute values of the coordinates do not exceed 100.
//
// Output
// Output a single number: the number of the corresponding quadrant, or 0 if it is impossible to uniquely determine the quadrant.
//
// Examples
//
// Input #1
// 12.5 30.0
//
// Answer #1
// 1

const std = @import("std");

pub fn main() void {
    std.debug.assert(quadrant(12.5, 30.0) == 1);
}

pub fn quadrant(x: f64, y: f64) isize {
    if (x == 0 or y == 0)
        return 0;
    if (x * y > 0) {
        if (x > 0)
            return 1;
        return 3;
    }
    if (x > 0)
        return 4;
    return 2;
}

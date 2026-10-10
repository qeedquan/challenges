// Find the area of rectangle.
//
// Input
// The integer sides of rectangle a and b (1≤a,b≤1000).
//
// Output
// Print the area of rectangle.
//
// Examples
//
// Input #1
// 3 4
//
// Answer #1
// 12

const std = @import("std");

pub fn main() void {
    std.debug.assert(solve(3, 4) == 12);
}

pub fn solve(a: isize, b: isize) isize {
    return a * b;
}

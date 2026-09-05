// Find the square of the sum of digits of a four-digit positive integer.
//
// Input
// One four-digit positive integer n.
//
// Output
// Print the square of the sum of the digits of n.
//
// Examples
//
// Input #1
// 4765
//
// Answer #1
// 484

const std = @import("std");

pub fn main() void {
    std.debug.assert(solve(4765) == 484);
}

pub fn solve(n: usize) usize {
    const r = digsum(n);
    return r * r;
}

pub fn digsum(n: usize) usize {
    var r: usize = 0;
    var m = n;
    while (m > 0) {
        r += m % 10;
        m = @divFloor(m, 10);
    }
    return r;
}

// Write the given three-digit natural number with its digits in reverse order.
//
// Input
// The input consists of a single line containing a three-digit natural number n.
//
// Output
// Output this number n with its digits in reverse order.
//
// Examples
// Input #1
// 198
//
// Answer #1
// 891

const std = @import("std");

pub fn main() void {
    std.debug.assert(digrev(198) == 891);
}

pub fn digrev(n: usize) usize {
    var r: usize = 0;
    var m = n;
    while (m > 0) {
        r = (r * 10) + (m % 10);
        m = @divTrunc(m, 10);
    }
    return r;
}

// Given the value of n. Compute the following sum: 1^2+2^2+3^2+...+n^2.
//
// Input
// One positive integer n (1≤n≤10^6).
//
// Output
// Print the value of the specified sum.
//
// Examples
// Input #1
// 3
//
// Answer #1
// 14

const std = @import("std");

pub fn main() void {
    std.debug.assert(solve(3) == 14);
}

// https://oeis.org/A000330
pub fn solve(n: usize) usize {
    return @divTrunc(n * (n + 1) * (2 * n + 1), 6);
}

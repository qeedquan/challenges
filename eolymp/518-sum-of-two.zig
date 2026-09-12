//
// Find the sum of two numbers.
//
// Input
// The first line contains the number of test cases t (1≤t≤100). Each of the following t lines contains two integers a and b.
//
// Output
// For each test case, print the sum of a and b on a separate line.
//
// Examples
//
// Input #1
// 3
// 2 3
// 17 -18
// 5 6
//
// Answer #1
// 5
// -1
// 11
//

const std = @import("std");

pub fn solve(a: isize, b: isize) isize {
    return a + b;
}

pub fn main() void {
    std.debug.print("{d}\n", .{solve(2, 3)});
    std.debug.print("{d}\n", .{solve(17, -18)});
    std.debug.print("{d}\n", .{solve(5, 6)});
}

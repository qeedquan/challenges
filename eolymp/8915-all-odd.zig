// Positive integer n is given. Print in increasing order all odd positive integers less than n.
//
// Input
// One positive integer n (n>1).
//
// Output
// Print in one line all odd positive integers less than n in increasing order.
//
// Examples
// Input #1
// 8
//
// Answer #1
// 1 3 5 7

const std = @import("std");

pub fn solve(n: usize) void {
    var i: usize = 1;
    while (i < n) {
        std.debug.print("{} ", .{i});
        i += 2;
    }
    std.debug.print("\n", .{});
}

pub fn main() void {
    solve(8);
}

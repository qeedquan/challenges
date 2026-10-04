// The race participants were assigned numbers from a to b, and all the information was recorded in the computer, but only in reverse order. Print the athletes' numbers.
//
// Input
// Two positive integers a and b (a≤b≤1000).
//
// Output
// Print the athletes' numbers in decreasing order.
//
// Examples
// Input #1
// 3 7
//
// Answer #1
// 7 6 5 4 3

const std = @import("std");

pub fn solve(a: isize, b: isize) void {
    var i: isize = b;
    while (i >= a) {
        std.debug.print("{} ", .{i});
        i -= 1;
    }
    std.debug.print("\n", .{});
}

pub fn main() void {
    solve(3, 7);
}

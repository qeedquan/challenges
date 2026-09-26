// An array of n integers is given. Print all its elements in a single column, do not change their initial order.
//
// Input
// The first line contains the number n (1≤n≤100). The second line contains n integers, each no more than 100 by absolute value.
//
// Output
// Print each element of the array on a separate line.
//
// Examples
//
// Input #1
// 4
// 5 0 -7 2
//
// Answer #1
// 5
// 0
// -7
// 2

const std = @import("std");

pub fn main() void {
    solve(&[_]isize{ 5, 0, -7, 2 });
}

pub fn solve(numbers: []const isize) void {
    for (numbers) |number| {
        std.debug.print("{d}\n", .{number});
    }
}

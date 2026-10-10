// Given positive integer n. Print the image of size n×n, formed by the asterisk and space characters as shown in the example.
//
// https://static.e-olymp.com/content/10/10ddff234c81509dd4270229e69cf039a808e1e8.jpg
//
// Input
// One positive integer n (n>1).
//
// Output
// Print the image n×n.
//
// Examples
//
// Input #1
// 5
//
// Answer #1
// *   *
//  * *
//   *
//  * *
// *   *

const std = @import("std");

pub fn main() void {
    solve(5);
}

pub fn solve(n: usize) void {
    for (0..n) |y| {
        for (0..n) |x| {
            if (x == y or x == n - y - 1) {
                std.debug.print("*", .{});
            } else {
                std.debug.print(" ", .{});
            }
        }
        std.debug.print("\n", .{});
    }
}

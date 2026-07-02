// Given a natural number n, produce a square matrix of dimensions n×n filled with the integers 0 and 1, following the pattern shown in the example.
//
// Input
// A natural number n, where 1≤n≤10.
//
// Output
// Display a matrix of size n×n that matches the pattern in the example.
//
// Examples
//
// Input #1
// 5
//
// Answer #1
// 01010
// 10101
// 01010
// 10101
// 01010

const std = @import("std");

pub fn main() void {
    solve(5);
    solve(6);
}

pub fn solve(n: usize) void {
    var y: usize = 0;
    while (y < n) {
        var x: usize = 0;
        while (x < n) {
            std.debug.print("{d}", .{(x ^ y) & 1});
            x += 1;
        }
        std.debug.print("\n", .{});
        y += 1;
    }
    std.debug.print("\n", .{});
}

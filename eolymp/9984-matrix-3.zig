// Given a natural number n, your task is to produce a square matrix of dimensions n×n.
// This matrix should be filled with integers ranging from 0 to n−1, following the pattern illustrated in the example.
//
// Input
// A natural number n, where 1≤n≤10.
//
// Output
// Display a matrix of size n×n, formatted as shown in the example.
//
// Examples
//
// Input #1
// 5
//
// Answer #1
// 01234
// 12340
// 23401
// 34012
// 40123

const std = @import("std");

pub fn main() void {
    solve(5);
    solve(6);
    solve(10);
}

pub fn solve(n: usize) void {
    var y: usize = 0;
    while (y < n) {
        var x: usize = 0;
        while (x < n) {
            std.debug.print("{d}", .{(x + y) % n});
            x += 1;
        }
        std.debug.print("\n", .{});
        y += 1;
    }
    std.debug.print("\n", .{});
}

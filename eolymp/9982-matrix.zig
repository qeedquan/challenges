// Given a natural number n, your task is to produce a square matrix of size n×n.
// This matrix should be filled with integers ranging from 0 to n−1, following the pattern demonstrated in the example.
//
// Input
// A natural number n, where 1≤n≤10.
//
// Output
// Display a matrix of size n×n, formatted as illustrated in the example.
//
// Examples
//
// Input #1
// 5
//
// Answer #1
// 00000
// 11111
// 22222
// 33333
// 44444

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
            std.debug.print("{d}", .{y});
            x += 1;
        }
        std.debug.print("\n", .{});
        y += 1;
    }
    std.debug.print("\n", .{});
}

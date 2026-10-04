// Given three real numbers x, y, z (-10^18≤x,y,z≤10^18). Print the value of expression x+y⋅z.
//
// Input
// Contains three lines: the first line contains number x, the second line contains number y, the third line contains number z.
//
// Output
// Print the value of expression x+y⋅z.
//
// Examples
//
// Input #1
// 1
// 1
// 1
//
// Answer #1
// 2
//
// Input #2
// 1.5
// 1.3
// 2.9
//
// Answer #2
// 5.27

const std = @import("std");

pub fn main() void {
    std.debug.print("{d}\n", .{solve(1, 1, 1)});
    std.debug.print("{d}\n", .{solve(1.5, 1.3, 2.9)});
}

pub fn solve(x: f64, y: f64, z: f64) f64 {
    return x + (y * z);
}

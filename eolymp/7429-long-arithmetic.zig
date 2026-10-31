// Calculate the result of adding or subtracting two large numbers.
//
// Input
// The first line contains a single number, which can be up to 255 characters long.The second line specifies the operation:+ for addition- for subtractionThe third line contains another number, also up to 255 characters long.
//
// Output
// Output a single number, which is the result of the specified operation on the two numbers.
//
// Examples
//
// Input #1
// 231211336
// +
// 967047652
//
// Answer #1
// 1198258988

const std = @import("std");

pub fn main() void {
    std.debug.print("{d}\n", .{add(231211336, 967047652)});
}

pub fn add(a: u1024, b: u1024) u1024 {
    return a + b;
}

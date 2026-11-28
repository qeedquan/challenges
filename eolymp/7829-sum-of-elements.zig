// Given sequence of n real numbers. Find the sum of all its elements.
//
// Input
// First line contains number n (n≤100). Next line contains n real numbers, each of them is no more than 100 by absolute value.
//
// Output
// Print the sum of all sequence elements with 1 digit after the decimal point.
//
// Examples
//
// Input #1
// 5
// 1.2 1.3 5.7 1.8 12.4
//
// Answer #1
// 22.4

const std = @import("std");

pub fn main() void {
    const numbers = [_]f64{ 1.2, 1.3, 5.7, 1.8, 12.4 };
    std.debug.print("{d}\n", .{sum(&numbers)});
}

pub fn sum(numbers: []const f64) f64 {
    var total: f64 = 0;
    for (numbers) |num| {
        total += num;
    }
    return total;
}

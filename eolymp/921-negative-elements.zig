// Given a sequence of n real numbers, numbered from 1 to n. Determine the number and the sum of negative elements in the sequence.
//
// Input
// The first line contains the number of elements n (n≤100).
// The second line contains n real numbers — the elements of the sequence, separated by spaces.
// Each value does not exceed 100 in absolute value.
//
// Output
// Print in a single line the number of negative elements and their sum, with two digits after the decimal point.
//
// Examples
//
// Input #1
// 5
// 6 -7.5 2.1 -2.0 0
//
// Answer #1
// 2 -9.50

const std = @import("std");

pub fn main() void {
    const result = solve(&[_]f64{ 6, -7.5, 2.1, -2.0, 0 });
    std.debug.print("{d} {d}\n", .{ result[0], result[1] });
}

pub fn solve(numbers: []const f64) struct { usize, f64 } {
    var length: usize = 0;
    var total: f64 = 0;
    for (numbers) |number| {
        if (number < 0) {
            length += 1;
            total += number;
        }
    }
    return .{ length, total };
}

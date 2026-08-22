// Find the sum of negative integers in the given array.
//
// Input
// The first line contains the number n. The second line contains n integers, each no more than 100 by absolute value.
//
// Output
// Print the sum of negative integers in the array. If there are no negative integers in array, print 0.
//
// Examples
//
// Input #1
// 5
// -5 6 8 -3 0
//
// Answer #1
// -8

const std = @import("std");

pub fn main() void {
    std.debug.assert(solve(&[_]isize{ -5, 6, 8, -3, 0 }) == -8);
}

pub fn solve(numbers: []const isize) isize {
    var result: isize = 0;
    for (numbers) |number| {
        if (number < 0)
            result += number;
    }
    return result;
}

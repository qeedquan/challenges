// Given n positive integers, find the greatest common divisor of these numbers.
//
// Input
// The first line contains one integer n (n≤1000). The second line contains n positive integers, each of which does not exceed 2⋅10^9.
//
// Output
// Print the greatest common divisor of the given numbers.
//
// Examples
// Input #1
// 5
// 125 80 67835 1000 25
//
// Answer #1
// 5

const std = @import("std");

pub fn main() void {
    std.debug.assert(solve(&[_]usize{ 125, 80, 67835, 1000, 25 }) == 5);
}

pub fn solve(numbers: []const usize) usize {
    var result: usize = 0;
    for (numbers) |number| {
        result = std.math.gcd(result, number);
    }
    return result;
}

// Determine if a given year is a leap year.
//
// A year qualifies as a leap year if it is divisible by 4, but not divisible by 100, unless it is also divisible by 400.
//
// Input
// The input consists of a single integer N, where 0≤N≤9999, representing the year.
//
// Output
// Print YES if the year is a leap year, otherwise print NO.
//
// Examples
//
// Input #1
// 4
//
// Answer #1
// YES

const std = @import("std");

pub fn solve(y: usize) []const u8 {
    if (y % 4 != 0)
        return "NO";

    if (y % 100 == 0 and y % 400 != 0)
        return "NO";

    return "YES";
}

pub fn main() void {
    std.debug.assert(std.mem.eql(u8, solve(4), "YES"));
    std.debug.assert(std.mem.eql(u8, solve(2000), "YES"));
}

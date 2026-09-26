// One integer n is given. Print "Ok" if n is a two-digit number, and "No" otherwise.
//
// Input
// One integer n (∣n∣≤10^9).
//
// Output
// Print "Ok" if n is a two-digit number, and "No" otherwise.
//
// Examples
//
// Input #1
// 17
//
// Answer #1
// Ok
//
// Input #2
// -123
//
// Answer #2
// No

const std = @import("std");

pub fn solve(n: isize) []const u8 {
    const x = @abs(n);
    if (10 <= x and x <= 99)
        return "Ok";
    return "No";
}

pub fn main() void {
    std.debug.assert(std.mem.eql(u8, solve(17), "Ok"));
    std.debug.assert(std.mem.eql(u8, solve(-123), "No"));
}

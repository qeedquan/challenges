// Check, if the given positive integer is a power of two.
//
// Input
// One positive integer n (n<2^31).
//
// Output
// Print "YES", if n is a power of two, and "NO" otherwise.
//
// Examples
// Input #1
// 16
//
// Answer #1
// YES
//
// Input #2
// 100
//
// Answer #2
// NO

const std = @import("std");

pub fn solve(n: usize) []const u8 {
    if (n > 0 and (n & (n - 1) == 0)) {
        return "YES";
    }
    return "NO";
}

pub fn main() void {
    std.debug.print("{s}\n", .{solve(16)});
    std.debug.print("{s}\n", .{solve(100)});
}

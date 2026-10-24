// Determine whether the number x belongs to the interval [a;b]. The number x belongs to the interval [a;b] if a≤x≤b.
//
// Input
// Three integers x,a,b, each not exceeding 10^9 in absolute value.
//
// Output
// Print "YES" if the number x belongs to the interval [a;b]. Otherwise, print "NO".
//
// Examples
// Input #1
// 4 2 6
//
// Answer #1
// YES
//
// Input #2
// 5 10 15
//
// Answer #2
// NO

const std = @import("std");

pub fn main() void {
    std.debug.assert(std.mem.eql(u8, solve(4, 2, 6), "YES"));
    std.debug.assert(std.mem.eql(u8, solve(5, 10, 15), "NO"));
}

pub fn solve(x: isize, a: isize, b: isize) []const u8 {
    if (a <= x and x <= b)
        return "YES";
    return "NO";
}

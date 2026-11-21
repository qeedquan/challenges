// The lengths of the sides of a triangle are given. Determine whether the triangle is right-angled.
//
// Input
// Three positive integers a,b,c — the lengths of the triangle's sides, each not exceeding 1000.
//
// Output
// Print "YES" if the triangle is right-angled, and "NO" otherwise.
//
// Examples
//
// Input #1
// 3 5 4
//
// Answer #1
// YES
//
// Input #2
// 3 5 5
//
// Answer #2
// NO

const std = @import("std");

pub fn solve(a: usize, b: usize, c: usize) []const u8 {
    var x = a;
    var y = b;
    var z = c;
    if (x > y)
        std.mem.swap(usize, &x, &y);
    if (x > z)
        std.mem.swap(usize, &x, &z);
    if (y > z)
        std.mem.swap(usize, &y, &z);
    if (x > 0 and (x * x) + (y * y) == (z * z))
        return "YES";
    return "NO";
}

pub fn main() void {
    std.debug.assert(std.mem.eql(u8, solve(3, 5, 4), "YES"));
    std.debug.assert(std.mem.eql(u8, solve(3, 5, 5), "NO"));
}

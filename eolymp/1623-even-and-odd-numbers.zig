// Three integers a, b, c are given. Determine if there is at least one even number and at least one odd number among them.
//
// Input
// Three integers a, b, c, each with absolute value not exceeding 10000 (numbers can be negative).
//
// Output
// Print YES if there is at least one even number and at least one odd number among a, b, and c. Otherwise, print NO.
//
// Examples
//
// Input #1
// 3 4 5
//
// Answer #1
// YES
//
// Input #2
// 7 7 7
//
// Answer #2
// NO

const std = @import("std");

pub fn solve(a: isize, b: isize, c: isize) []const u8 {
    var r = [2]usize{ 0, 0 };
    r[@intCast(a & 1)] += 1;
    r[@intCast(b & 1)] += 1;
    r[@intCast(c & 1)] += 1;
    if (r[0] != 0 and r[1] != 0) {
        return "YES";
    }
    return "NO";
}

pub fn main() void {
    std.debug.assert(std.mem.eql(u8, solve(3, 4, 5), "YES"));
    std.debug.assert(std.mem.eql(u8, solve(7, 7, 7), "NO"));
}

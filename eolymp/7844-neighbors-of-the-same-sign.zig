// Array of n integers is given. Print the pairs of adjacent elements of the same sign. If there are no adjacent elements of the same sign, print nothing.
//
// Input
// The first line contains number n. The next line contains n integers. All numbers do not exceed 100 by absolute value.
//
// Output
// Print the pairs of adjacent elements of the same sign.
//
// Examples
// Input #1
// 7
// 9 5 -7 -7 5 -9 -4
//
// Answer #1
// 9 5
// -7 -7
// -9 -4
//
// Input #2
// 10
// -8 -10 -2 1 -9 5 -9 0 0 -9
//
// Answer #2
// -8 -10
// -10 -2

const std = @import("std");

pub fn main() void {
    solve(&[_]isize{ 9, 5, -7, -7, 5, -9, -4 });
    solve(&[_]isize{ -8, -10, -2, 1, -9, 5, -9, 0, 0, -9 });
}

pub fn solve(a: []const isize) void {
    var i: usize = 0;
    while (i + 1 < a.len) {
        if (sign(a[i]) == sign(a[i + 1]) and a[i] != 0) {
            std.debug.print("{d} {d}\n", .{ a[i], a[i + 1] });
        }
        i += 1;
    }
    std.debug.print("\n", .{});
}

pub fn sign(x: isize) isize {
    if (x < 0)
        return -1;
    if (x == 0)
        return 0;
    return 1;
}

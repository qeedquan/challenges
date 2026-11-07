// An array of integers is given. Print all elements that are greater than their previous element.
//
// Input
// The first line contains the integer n — the number of elements in the array. The second line contains n integers. Each number does not exceed 100 in absolute value.
//
// Output
// Print all elements of the array that are strictly greater than the previous element.
//
// Examples
//
// Input #1
// 7
// 14 16 3 7 17 19 9
//
// Answer #1
// 16 7 17 19

const std = @import("std");

pub fn main() void {
    solve(&[_]isize{ 14, 16, 3, 7, 17, 19, 9 });
}

pub fn solve(a: []const isize) void {
    var i: usize = 1;
    while (i < a.len) {
        if (a[i] > a[i - 1])
            std.debug.print("{d} ", .{a[i]});
        i += 1;
    }
    std.debug.print("\n", .{});
}

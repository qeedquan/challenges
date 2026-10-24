// An array of n integers is given. Print all elements located at even positions. The indexing of elements starts from 0.
//
// Input
// The first line contains the integer n. The second line contains n integers. Each integer does not exceed 100 in absolute value.
//
// Output
// Print the elements of the array with even indices.
//
// Examples
//
// Input #1
// 7
// 14 16 3 7 17 19 9
//
// Answer #1
// 14 3 17 9

const std = @import("std");

pub fn main() void {
    solve(&[_]isize{ 14, 16, 3, 7, 17, 19, 9 });
}

pub fn solve(array: []const isize) void {
    var index: usize = 0;
    while (index < array.len) {
        std.debug.print("{d} ", .{array[index]});
        index += 2;
    }
    std.debug.print("\n", .{});
}

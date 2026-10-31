// Create a program that outputs an inverted right-angled triangle composed of asterisks, where both legs have a length of n.
//
// Input
// You will receive an integer n (2≤n≤50), representing the length of the triangle's legs.
//
// Output
// Display an inverted right-angled triangle of asterisks with the specified dimensions.
//
// Examples
//
// Input #1
// 3
//
// Answer #1
// ***
// **
// *
//
// Input #2
// 5
//
// Answer #2
// *****
// ****
// ***
// **
// *

const std = @import("std");

pub fn main() void {
    solve(3);
    solve(5);
}

pub fn solve(n: isize) void {
    var i = n;
    while (i >= 1) {
        var j: isize = 1;
        while (j <= i) {
            std.debug.print("*", .{});
            j += 1;
        }
        std.debug.print("\n", .{});
        i -= 1;
    }
}

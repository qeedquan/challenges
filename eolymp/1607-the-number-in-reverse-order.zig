// Write a nonnegative integer n in reverse order.
//
// Input
// One nonnegative 64-bit integer n.
//
// Output
// Print the number n in reverse order.
//
// Examples
//
// Input #1
// 1234
//
// Answer #1
// 4321
//
// Input #2
// 100
//
// Answer #2
// 001

const std = @import("std");

pub fn main() void {
    var x1 = "1234".*;
    var x2 = "100".*;

    std.mem.reverse(u8, &x1);
    std.mem.reverse(u8, &x2);

    std.debug.print("{s}\n", .{x1});
    std.debug.print("{s}\n", .{x2});
}

// https://static.eolymp.com/content/sq/sql28tsf8977ned17jd3nu3q1g.jpg
//
// The program takes an integer n as input, representing the number of steps. Your task is to print the steps in a downward pattern using spaces and hash symbols #, as illustrated in the example.
//
// Input
// A natural number n, where 1≤n≤100
//
// Output
// Print the steps in the format shown in the example image.
//
// Examples
//
// Input #1
// 5
//
// Answer #1
// #
// ##
// ###
// ####
// #####

const std = @import("std");

pub fn main() void {
    solve(5);
    solve(6);
}

pub fn solve(n: usize) void {
    var y: usize = 0;
    while (y < n) {
        var x: usize = 0;
        while (x <= y) {
            std.debug.print("#", .{});
            x += 1;
        }
        std.debug.print("\n", .{});
        y += 1;
    }
    std.debug.print("\n", .{});
}

// The program takes an integer n as input, representing the number of steps.
// Your task is to print the steps in an upward pattern using spaces and the hash symbol #, as illustrated in the example.
//
// https://static.eolymp.com/content/50/5026dmhvn95q91pirdljub0rg0.jpg
//
// Input
// A natural number n, where 1≤n≤100
//
// Output
// Print the steps in the format shown in the image.
//
// Examples
//
// Input #1
// 5
//
// Answer #1
//     #
//    ##
//   ###
//  ####
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
        while (x < n - y - 1) {
            std.debug.print(" ", .{});
            x += 1;
        }
        while (x < n) {
            std.debug.print("#", .{});
            x += 1;
        }
        std.debug.print("\n", .{});
        y += 1;
    }
    std.debug.print("\n", .{});
}

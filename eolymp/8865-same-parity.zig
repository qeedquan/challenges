// The input for the program consists of two integers, n and m, provided on a single line and separated by a space.
// The program should output 1 if both integers have the same parity (meaning both are either even or odd), and 0 if they do not.
//
// Input
// A single line containing two integers.
//
// Output
// The result of the problem.
//
// Examples
//
// Input #1
// 7 4
//
// Answer #1
// 0
//
// Input #2
// -2 8
//
// Answer #2
// 1

const std = @import("std");

pub fn solve(n: isize, m: isize) isize {
    return ((n ^ m) & 1) ^ 1;
}

pub fn main() void {
    std.debug.assert(solve(7, 4) == 0);
    std.debug.assert(solve(-2, 8) == 1);
    std.debug.assert(solve(0, 1) == 0);
    std.debug.assert(solve(1, 3) == 1);
}

//
// The program receives a natural number n as input. Your task is to determine and output the count of odd natural numbers that are less than or equal to n.
//
// Input
// A natural number n, where n is at most 10^18.
//
// Output
// The count of odd natural numbers not exceeding n.
//
// Examples
// Input #1
// 7
// Answer #1
// 4
// Input #2
// 6
// Answer #2
// 3

const std = @import("std");

pub fn solve(n: usize) usize {
    return @divFloor(n, 2) + (n & 1);
}

pub fn solvebf(n: usize) usize {
    var r: usize = 0;
    var i: usize = 1;
    while (i <= n) {
        r += 1;
        i += 2;
    }
    return r;
}

pub fn main() void {
    std.debug.assert(solve(7) == 4);
    std.debug.assert(solve(6) == 3);
    for (0..100000) |i| {
        std.debug.assert(solve(i) == solvebf(i));
    }
}

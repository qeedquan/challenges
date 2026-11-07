// Find the sum of two proper fractions a/b and c/d. Present the result as an irreducible fraction. If the result is an integer, then print only this integer.
//
// Input
// One line contains four positive integers a,b,c,d — the numerators and denominators of the fractions. All numbers do not exceed 1000.
//
// Output
// Print the numerator and denominator of the resulting fraction, or an integer if the result is a whole number.
//
// Examples
//
// Input #1
// 1 2 1 4
//
// Answer #1
// 3 4
//
// Input #9
// 3 4 1 4
//
// Answer #9
// 1

const std = @import("std");

pub fn main() void {
    std.debug.print("{any}\n", .{solve(1, 2, 1, 4)});
    std.debug.print("{any}\n", .{solve(3, 4, 1, 4)});
}

pub fn solve(a: usize, b: usize, c: usize, d: usize) struct { usize, usize } {
    const x = (a * d) + (b * c);
    const y = b * d;
    const m = std.math.gcd(x, y);
    return .{ @divTrunc(x, m), @divTrunc(y, m) };
}

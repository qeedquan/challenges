// We call k the magic constant for number n, if 1+2+3+…+(k−1)+k=n. Your task is to find the magic constant for a given number.
//
// Input
// One number n (1≤n≤10^18).
//
// Output
// Print the magic constant for number n, if it exists and −1 otherwise.
//
// Examples
//
// Input #1
// 3
//
// Answer #1
// 2
//
// Input #2
// 2
//
// Answer #2
// -1

const std = @import("std");

pub fn main() void {
    std.debug.assert(solve(3) == 2);
    std.debug.assert(solve(2) == -1);
}

pub fn solve(n: usize) isize {
    const t = (8 * n) + 1;
    const s = std.math.sqrt(t);
    if (s * s != t or s == 0)
        return -1;
    return @divTrunc(s - 1, 2);
}

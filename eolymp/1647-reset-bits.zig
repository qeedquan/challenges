// Given two integers n and k. Reset (set to zero) the last k bits in the number n, and print the result.
// It is recommended to solve this problem without using loops.
//
// https://static.e-olymp.com/content/ac/acb944d9a2a55b18229bc3e8d2fa6a42e4431ab7.gif
//
// Input
// Two numbers n (0≤n≤2^31-1) and k (0≤k≤30).
//
// Output
// Print the result of resetting the last k bits in n.
//
// Examples
// Input #1
// 5 1
//
// Answer #1
// 4

const std = @import("std");

pub fn main() void {
    std.debug.assert(solve(5, 1) == 4);
}

pub fn solve(n: usize, k: u6) usize {
    var r = n;
    r >>= k;
    r <<= k;
    return r;
}

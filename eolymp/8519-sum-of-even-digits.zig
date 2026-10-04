// One long integer is given. Find the sum of its even digits.
//
// Input
// One positive integer n (n≤10^100).
//
// Output
// Print the sum of even digits in number n.
//
// Examples
// Input #1
// 2345
//
// Answer #1
// 6
//
// Input #2
// 3458937487534533459
//
// Answer #2
// 32

const std = @import("std");

pub fn main() void {
    std.debug.assert(solve(2345) == 6);
    std.debug.assert(solve(3458937487534533459) == 32);
}

pub fn solve(n: usize) usize {
    var r: usize = 0;
    var m = n;
    while (m > 0) {
        if ((m & 1) == 0)
            r += m % 10;
        m = @divTrunc(m, 10);
    }
    return r;
}

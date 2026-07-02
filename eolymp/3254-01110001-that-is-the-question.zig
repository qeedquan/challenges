// As you know, the number in binary is written using the digits 0 and 1. You must convert number from binary to decimal.
//
// Input
// One nonnegative integer in binary notation. Contains no more than 15 digits. The notation can start from zeros.
//
// Output
// Print the decimal representation of the input binary number.
//
// Examples
//
// Input #1
// 101
//
// Answer #1
// 5
//
// Input #2
// 01
//
// Answer #2
// 1
//
// Input #3
// 00110011
//
// Answer #3
// 51
//
// Input #4
// 1111
//
// Answer #4
// 15

const std = @import("std");

pub fn main() void {
    std.debug.assert(solve("101") == 5);
    std.debug.assert(solve("01") == 1);
    std.debug.assert(solve("00110011") == 51);
    std.debug.assert(solve("1111") == 15);
}

pub fn solve(s: []const u8) usize {
    var r: usize = 0;
    for (s) |c| {
        r <<= 1;
        if (c == '1')
            r |= 1;
    }
    return r;
}

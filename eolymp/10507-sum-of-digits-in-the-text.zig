// The text is given. Find the sum of all digits in it.
//
// Input
// Contains sequence of characters — a text.
//
// Output
// Print the sum of all digits in the text.
//
// Examples
// Text contains digits 4,1,2,4. Their sum is 4+1+2+4=11.
//
// Input #1
// Cats =="+41"
//   Dogs 2 and 4pigs
//
// Answer #1
// 11

const std = @import("std");

pub fn main() void {
    std.debug.assert(solve("Cats ==\"+41\"\n  Dogs 2 and 4pigs") == 11);
}

pub fn solve(string: []const u8) usize {
    var result: usize = 0;
    for (string) |symbol| {
        if ('0' <= symbol and symbol <= '9')
            result += symbol - '0';
    }
    return result;
}

// Determine the number of words in the given text fragment.
//
// Input
// The only line contains a fragment of text in English, with a length not exceeding 250 characters.
// It is guaranteed that the text does not contain hyphens, dashes, or digits.
//
// Output
// Print the number of words in the text fragment.
//
// Examples
//
// Input #1
// Hello world!
//
// Answer #1
// 2
//
// Input #2
// Hello world! Hello,    country!
//
// Answer #2
// 4

const std = @import("std");

pub fn main() void {
    std.debug.assert(solve("Hello world!") == 2);
    std.debug.assert(solve("Hello world! Hello,    country!") == 4);
}

pub fn solve(text: []const u8) usize {
    var total: usize = 0;
    var iter = std.mem.tokenizeSequence(u8, text, " ");
    while (iter.next()) |_| {
        total += 1;
    }
    return total;
}

// To be or not to be? – that is the question...
//
// Hamlet – Prince of Denmark
//
// Ruslan dreams of becoming a millionaire, and in his opinion, to achieve this, he should become Bill Gates—well, a programmer...
//
// To reach this goal, he dedicates any spare (and not so spare) moment to solving programming problems.
// So if there is an unimportant (in his view) or uninteresting lesson at the moment,
// Ruslan asks to leave the classroom, takes out his old mobile phone connected to the Internet in the hallway, and starts solving problems right away.
// Today, as usual, he has begun coding during class, but there's a problem—the phone does not have enough memory,
// and the numbers in the problem are not only large but also numerous.
//
// And the problem itself is very simple: "Count how many of the given integers are powers of two."
//
// Help Ruslan make another step toward his dream of becoming a millionaire!
//
// Input
// The first line contains the number of integers n (1≤n≤10^6).
// The second line contains n integers.
// All numbers in the second line are positive and do not exceed 18446744073709551615.
//
// Output
// The number of integers that are powers of two.
//
// Examples
//
// Input #1
// 10
// 3 4 8 4 256 64 4 11 13 4
//
// Answer #1
// 7

const std = @import("std");

pub fn main() void {
    std.debug.assert(solve(&[_]usize{ 13, 4, 8, 4, 256, 64, 4, 11, 13, 4 }) == 7);
}

pub fn solve(a: []const usize) usize {
    var r: usize = 0;
    for (a) |x| {
        if (ispow2(x))
            r += 1;
    }
    return r;
}

pub fn ispow2(x: usize) bool {
    return x > 0 and (x & (x - 1)) == 0;
}

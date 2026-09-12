// There are n stones on the table. Two players take turns making moves. On each turn, a player can take:
//
// 1 or 2 stones, if n is divisible by 3;
//
// 1 or 3 stones, if n divided by 3 leaves remainder 1;
//
// 1, 2, or 3 stones, if n divided by 3 leaves remainder 2.
//
// A move can only be made if there are enough stones remaining. The player who cannot make a move loses the game.
//
// Input
// The input consists of a single integer n (0<n≤100).
//
// Output
// Print a single integer 1 or 2 — the number of the player who will win if both play optimally.
//
// Examples
// Input #1
// 3
//
// Answer #1
// 2

const std = @import("std");

pub fn main() void {
    std.debug.assert(solve(3) == 2);
}

pub fn solve(n: isize) isize {
    if (@mod(n, 3) == 0)
        return 2;
    return 1;
}

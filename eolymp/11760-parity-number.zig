// Дано ціле число A. Залежно від того, чи воно парне, або непарне, обчисліть:
//
// якщо число A парне — квадрат цього числа;
//
// якщо число A непарне — куб цього числа.
//
// Input
// В єдиному рядку записано число A (1≤A≤10000).
//
// Output
// Виведіть одне число — відповідь на задачу.
//
// Examples
//
// Input #1
// 2
//
// Answer #1
// 4
//
// Input #2
// 3
//
// Answer #2
// 27

const std = @import("std");

pub fn solve(n: usize) usize {
    if (n & 1 != 0) {
        return n * n * n;
    }
    return n * n;
}

pub fn main() void {
    std.debug.assert(solve(2) == 4);
    std.debug.assert(solve(3) == 27);
}

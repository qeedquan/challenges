// An array of n integers is given. Cyclically shift the elements of the array one position to the right.
//
// Input
// The first line contains the number of elements in the array n (n≤100). The second line contains n integers, each of which does not exceed 100 in absolute value.
//
// Output
// Output n numbers in a single line — the new values of the array after the shift.
//
// Examples
//
// Input #1
// 4
// 1 2 3 4
//
// Answer #1
// 4 1 2 3

const std = @import("std");

pub fn main() !void {
    var numbers = [_]isize{ 1, 2, 3, 4 };
    solve(&numbers);
    std.debug.print("{any}\n", .{numbers});
}

pub fn solve(numbers: []isize) void {
    if (numbers.len == 0)
        return;

    const element = numbers[numbers.len - 1];
    std.mem.copyBackwards(isize, numbers[1..numbers.len], numbers[0..(numbers.len - 1)]);
    numbers[0] = element;
}

// You have been assigned a crucial mission: to determine if numbers are prime. The galaxy is counting on you!
//
// Input
// You will be given a single number N (2≤N≤10^9).
//
// Output
// Print True if the number is prime, and False if it is composite.
//
// Examples
// Input #1
// 2
//
// Answer #1
// True

const std = @import("std");

pub fn main() void {
    var i: isize = 0;
    while (i <= 1000) : (i += 1) {
        if (isprime(i))
            std.debug.print("{d}\n", .{i});
    }
}

pub fn isprime(n: isize) bool {
    if (n <= 1)
        return false;
    if (n == 2 or n == 3)
        return true;
    if (@mod(n, 2) == 0)
        return false;

    var i: isize = 3;
    while (i * i <= n) : (i += 2) {
        if (@mod(n, i) == 0)
            return false;
    }
    return true;
}

// Gray codes are named after Frank Gray, a physicist from Bell Telephone Laboratories.
// In the 1930s, he developed a method that is still used today for transmitting color television signals.
// This method allows a color signal to be displayed in shades of gray when received by a black-and-white receiver.
//
// There are various types of Gray codes, but we'll focus on one specific type: binary reflected Gray code.
// This is the standard Gray code referred to when no specific type is mentioned.
//
// The binary reflected Gray code is constructed as follows: We begin with the sequences 0 and 1, representing the integers 0 and 1, respectively.
//
// 0 1
// Next, we reflect these sequences across the horizontal axis and prepend a 1 to the new entries, while prepending a 0 to the existing entries.
//
// 00 01 11 10
// This process yields the reflected Gray code for n=2. To generate the code for n=3, we repeat the procedure:
//
// 000 001 011 010 110 111 101 100
// Using this construction method, we can observe by induction on n that: first, each of the 2^n bit combinations appears exactly once in the list;
// second, transitioning from one list element to the next involves changing only one bit;
// and third, transitioning from the last list element back to the first also involves changing only one bit.
// Gray codes with this last property are termed cyclic, and the reflected Gray code is inherently cyclic.
//
// For each given number k, you need to output the decimal value of the k-th Gray code.
//
// Input
// The input consists of multiple test cases, each containing a single number k (0≤k≤10^18) on a separate line. The total number of test cases does not exceed 10^5.
//
// Output
// For each number k provided, output the decimal value of the k-th Gray code on a separate line.
//
// Examples
// Input #1
// 3
// 14
// 5
// 12
//
// Answer #1
// 2
// 9
// 7
// 10

const std = @import("std");

pub fn main() void {
    std.debug.assert(solve(3) == 2);
    std.debug.assert(solve(14) == 9);
    std.debug.assert(solve(5) == 7);
    std.debug.assert(solve(12) == 10);
}

pub fn solve(n: usize) usize {
    return n ^ (n >> 1);
}

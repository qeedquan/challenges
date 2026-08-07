/*

The task is to count the number of disjoint 11 blocks in a 64-bit word, using the minimum number of straight-line instructions. That is, how many nonoverlapping neighbored pairs of 1-bits can be found.

Examples
(imagine leading zeros to fill up to 64 bits)

      Input Output
     111111      3
    1110111      2
11110010111      3
Here is a possible implementation (that would not be a valid answer since it uses a loop and a condition):

uint64_t f(uint64_t x) {
    uint64_t n = 0;
    while (x)
        if ((x & 3) == 3)
            ++n, x >>= 2;
        else
            x >>= 1;
    return n;
}
Scoring
The goal is to minimize the number of instructions. Instructions allowed are only the basic bitwise and arithmetic operators (|, &, ^, +, -, ~, <<, >> (arithmetic shift)) plus popcount (count the number of bits set in a word). Using 64-bit constants is free. No loops, conditions etc. are allowed. Example of a three-instruction function that makes it easy to count the number of instructions:

uint64_t f(uint64_t x) {
    uint64_t t0 = x ^ 0xff00ff00ff00ff00;
    uint64_t t1 = t0 - 1;
    uint64_t t2 = popcount(t1);
    return t2;
}
but it's also fine to present it in more readable form.

*/

fn main() {
    assert_eq!(count(0b111111), 3);
    assert_eq!(count(0b1110111), 2);
    assert_eq!(count(0b11110010111), 3);
}

fn count(mut x: usize) -> usize {
    let mut n = 0;
    while x != 0 {
        if (x & 3) == 3 {
            n += 1;
            x >>= 1;
        }
        x >>= 1;
    }
    return n;
}

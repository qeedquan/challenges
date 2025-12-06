/*

Problem:

Your goal is to add two input numbers without using any of the following math operators: +,-,*,/.

Additionally, you can't use any built-in functions that are designed to replace those math operators.

Scoring:

Smallest code (in number of bytes) wins.

Update

Most of the programs i've seen either concatenate two arrays containing their numbers, or make first number of a character, append second number characters, then count them all.

*/

fn main() {
    let n = 5000;
    for x in -n..n {
        for y in -n..n {
            assert_eq!(add(x, y), x + y);
        }
    }
}

fn add(mut x: isize, mut y: isize) -> isize {
    while y != 0 {
        x ^= y;
        y = (y & (x ^ y)) << 1;
    }
    x
}

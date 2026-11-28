/*

In this simple assignment you are given a number and have to make it negative. But maybe the number is already negative?

Examples
Kata.MakeNegative(1);  // return -1
Kata.MakeNegative(-5); // return -5
Kata.MakeNegative(0);  // return 0

Notes
The number can be negative already, in which case no change is required.
Zero (0) is not checked for any specific sign. Negative zeros make no mathematical sense.

*/

fn main() {
    assert_eq!(neg(1), -1);
    assert_eq!(neg(-5), -5);
    assert_eq!(neg(0), 0);
}

fn neg(mut x: isize) -> isize {
    if x > 0 {
        x = -x;
    }
    x
}

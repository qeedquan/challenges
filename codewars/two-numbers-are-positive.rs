/*

Task:
Your job is to write a function, which takes three integers a, b, and c as arguments, and returns True if exactly two of of the three integers are positive numbers (greater than zero), and False - otherwise.

Examples:
twoArePositive(2, 4, -3) == true
twoArePositive(-4, 6, 8) == true
twoArePositive(4, -6, 9) == true
twoArePositive(-4, 6, 0) == false
twoArePositive(4, 6, 10) == false
twoArePositive(-14, -3, -4) == false

*/

fn main() {
    assert_eq!(two_are_positive(2, 4, -3), true);
    assert_eq!(two_are_positive(-4, 6, 8), true);
    assert_eq!(two_are_positive(4, -6, 9), true);
    assert_eq!(two_are_positive(-4, 6, 0), false);
    assert_eq!(two_are_positive(4, 6, 10), false);
    assert_eq!(two_are_positive(-14, -3, -4), false);
}

fn two_are_positive(a: isize, b: isize, c: isize) -> bool {
    sign(a) + sign(b) + sign(c) == 1
}

fn sign(x: isize) -> isize {
    if x > 0 {
        1
    } else {
        -1
    }
}

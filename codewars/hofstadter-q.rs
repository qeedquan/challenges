/*

Hofstadter sequences are a family of related integer sequences, among which the first ones were described by an American professor Douglas Hofstadter in his book Gödel, Escher, Bach.

Task
Today we will be implementing the rather chaotic recursive sequence of integers called Hofstadter Q.

The Hofstadter Q is defined as:

Q(1) = Q(2) = 1,
Q(n) = Q(n - Q(n - 1)) + Q(n - Q(n - 2)), n > 2.

As the author states in the aforementioned book:


It is reminiscent of the Fibonacci definition in that each new value is a sum of two previous values-but not of the immediately previous two values. Instead, the two immediately previous values tell how far to count back to obtain the numbers to be added to make the new value.
The function produces the starting sequence:
1, 1, 2, 3, 3, 4, 5, 5, 6 . . .
Test info: 100 random tests, n is always positive

Good luck!

*/

#![allow(non_snake_case)]

fn main() {
    let tab = vec![
        1, 1, 2, 3, 3, 4, 5, 5, 6, 6, 6, 8, 8, 8, 10, 9, 10, 11, 11, 12, 12, 12, 12, 16, 14, 14,
        16, 16, 16, 16, 20, 17, 17, 20, 21, 19, 20, 22, 21, 22, 23, 23, 24, 24, 24, 24, 24, 32, 24,
        25, 30, 28, 26, 30, 30, 28, 32, 30, 32, 32, 32, 32, 40, 33, 31, 38, 35, 33, 39, 40, 37, 38,
        40, 39,
    ];

    assert_eq!(Q(tab.len()), tab);
}

// http://oeis.org/A005185
fn Q(n: usize) -> Vec<usize> {
    if n < 1 {
        return vec![];
    }

    let mut p = vec![1; n];
    for i in 2..n {
        p[i] = p[i - p[i - 1]] + p[i - p[i - 2]];
    }
    return p;
}

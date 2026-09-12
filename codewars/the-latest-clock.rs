/*

Write a function which receives 4 digits and returns the latest time of day that can be built with those digits.

The time should be in HH:MM format.

Examples:

digits: 1, 9, 8, 3 => result: "19:38"
digits: 9, 1, 2, 5 => result: "21:59" (19:25 is also a valid time, but 21:59 is later)
Notes
Result should be a valid 24-hour time, between 00:00 and 23:59.
Only inputs which have valid answers are tested.

*/

use std::cmp::max;

fn main() {
    assert_eq!(latest_clock(1, 9, 8, 3), "19:38");
    assert_eq!(latest_clock(9, 1, 2, 5), "21:59");
}

fn latest_clock(a: usize, b: usize, c: usize, d: usize) -> String {
    let p = vec![
        [a, b, c, d],
        [a, b, d, c],
        [a, c, b, d],
        [a, c, d, b],
        [a, d, b, c],
        [a, d, c, b],
        [b, a, c, d],
        [b, a, d, c],
        [b, c, a, d],
        [b, c, d, a],
        [b, d, a, c],
        [b, d, c, a],
        [c, b, a, d],
        [c, b, d, a],
        [c, a, b, d],
        [c, a, d, b],
        [c, d, b, a],
        [c, d, a, b],
        [d, b, c, a],
        [d, b, a, c],
        [d, c, b, a],
        [d, c, a, b],
        [d, a, b, c],
        [d, a, c, b],
    ];

    let mut t = 0;
    for i in p {
        let h = (i[0] * 10) + i[1];
        let m = (i[2] * 10) + i[3];
        if h <= 23 && m <= 59 {
            t = max(t, (h * 60) + m);
        }
    }
    format!("{}:{}", t / 60, t % 60)
}

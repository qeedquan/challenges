/*

Since the start of the day, m minutes have elapsed. What is the current time displayed on the clock in terms of hours and minutes?

Input
An integer m that is less than 1440.

Output
Two integers on a single line, separated by a space.

Examples

Input #1
127

Answer #1
2 7

*/

fn main() {
    assert_eq!(solve(127), (2, 7));
}

fn solve(m: isize) -> (isize, isize) {
    (m / 60, m % 60)
}

/*

Two trains depart simultaneously from different cities towards each other.
They meet after t hours. After an additional t1 hours, the first train arrives at the station from which the second train started.
In how many hours and minutes after departure will the second train reach the station from which the first train started?

Input
The input contains two non-negative integers t and t1, with 0≤t,t1≤24.

Output
Print the time, in hours and minutes, after departure when the second train will arrive at the station where the first train started.

Examples

Input #1
4 3

Answer #1
5 20

*/

fn main() {
    assert_eq!(solve(4, 3), (5, 20));
}

fn solve(t1: isize, t2: isize) -> (isize, isize) {
    let t = (60 * t1 * t1) / t2;
    (t / 60, t % 60)
}

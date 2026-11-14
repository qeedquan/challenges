/*

At the Informatics Olympiad, n teams have arrived, with ai (1≤i≤n) participants in the i-th team.
For the competition, classrooms have been prepared, each equipped with m computers.

Determine the minimum number of classrooms that must be used, given that each classroom may contain only participants from different teams.
In other words, no classroom may have more than one participant from the same team.

Input
The first line contains two integers n and m. The second line contains n integers ai (1≤i≤n).
All values are integers, non-negative, and do not exceed 100.

Output
Print one integer — the minimum required number of classrooms.

Examples

Input #1
5 3
2 3 4 1 2

Answer #1
4

*/

use std::cmp::max;

fn main() {
    assert_eq!(solve(&[2, 3, 4, 1, 2], 3), 4);
}

fn solve(a: &[isize], m: isize) -> isize {
    let (mut r, mut s) = (0, 0);
    for &x in a {
        s += x;
        r = max(r, x);
    }
    if m != 0 {
        r = max(r, (s + m - 1) / m);
    }
    return r;
}

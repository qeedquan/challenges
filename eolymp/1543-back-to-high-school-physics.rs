/*

Some particle starts moving from rest with constant acceleration. After time t from the start of the motion, the particle's velocity becomes v.
What distance will the particle travel in time 2t?

Input
Each line is a separate test and contains two integers: the particle's velocity v (0≤v≤100) and the time t (0≤t≤200) at which the particle reached this velocity.

Output
For each test, print the distance the particle will move in time 2t on a separate line.

Examples

Input #1
0 0
5 12

Answer #1
0
120

*/

fn main() {
    assert_eq!(displacement(0, 0), 0);
    assert_eq!(displacement(5, 12), 120);
}

fn displacement(v: isize, t: isize) -> isize {
    2 * v * t
}

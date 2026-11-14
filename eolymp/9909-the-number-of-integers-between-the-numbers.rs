/*

Determine and output the number of integers that exist between the integers a and b.

Input
Two integers a and b in one line, separated by a space, each not exceeding 10^18.

Output
The solution to the problem.

Examples

Input #1
-2 6

Answer #1
7

Input #2
9 3

Answer #2
5

*/

fn main() {
    assert_eq!(solve(-2, 6), 7);
    assert_eq!(solve(9, 3), 5);
}

fn solve(mut a: isize, mut b: isize) -> isize {
    if a > b {
        (a, b) = (b, a);
    }
    b - a - 1
}

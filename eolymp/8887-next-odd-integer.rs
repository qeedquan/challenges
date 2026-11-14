/*

Integer n is given. Print the next odd integer after n.

Input
One integer n.

Output
Print the odd integer after n.

Examples

Input #1
7

Answer #1
9

Input #2
6

Answer #2
7

*/

fn main() {
    assert_eq!(solve(0), 1);
    assert_eq!(solve(1), 3);
    assert_eq!(solve(2), 3);
    assert_eq!(solve(3), 5);
    assert_eq!(solve(4), 5);
    assert_eq!(solve(5), 7);
    assert_eq!(solve(6), 7);
    assert_eq!(solve(7), 9);
    assert_eq!(solve(8), 9);
}

fn solve(n: isize) -> isize {
    n + 1 + (n & 1)
}

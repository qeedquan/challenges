/*

An integer n is given. Find the number of positive integers between 1 and n.

Input
One integer n, no more than 10^18 by absolute value.

Output
Print the number of positive integers between 1 and n.

Examples
Input #0
10

Answer #0
10

*/

fn main() {
    assert_eq!(solve(10), 10);
}

fn solve(n: i128) -> i128 {
    if n < 1 {
        return 0;
    }
    return n;
}

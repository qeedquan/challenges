/*

Determine how many two-digit numbers have digits that are in increasing order and add up to m.

Input
A natural number m, where 0≤m≤20.

Output
A single integer representing the solution to the problem.

Examples
Input #1
3

Answer #1
1

Input #2
2

Answer #2
0

*/

fn main() {
    assert_eq!(solve(3), 1);
    assert_eq!(solve(2), 0);
}

fn solve(m: usize) -> usize {
    let mut r = 0;
    for i in 1..=9 {
        for j in i + 1..=9 {
            if digsum((i * 10) + j) == m {
                r += 1;
            }
        }
    }
    r
}

fn digsum(mut n: usize) -> usize {
    let mut r = 0;
    while n > 0 {
        r += n % 10;
        n /= 10;
    }
    r
}

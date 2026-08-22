/*

Display the first n numbers of the sequence 2 6 12 20 30 …

Input
A natural number n, 1≤n≤100

Output
The numbers of the sequence, separated by spaces, in a single line.

Examples

Input #1
7
Answer #1
2 6 12 20 30 42 56

*/

fn main() {
    assert_eq!(solve(7), vec![2, 6, 12, 20, 30, 42, 56]);
}

fn solve(n: usize) -> Vec<usize> {
    let mut r = vec![];
    for x in 1..=n {
        r.push((x * x) + x);
    }
    r
}

/*

Display the first n numbers of the sequence: 2 4 8 16 32 …

Input
A natural number n, where 1≤n≤63.

Output
Print the numbers of the sequence on a single line, separated by spaces.

Examples
Input #1
7
Answer #1
2 4 8 16 32 64 128

*/

fn main() {
    assert_eq!(solve(7), vec![2, 4, 8, 16, 32, 64, 128]);
}

fn solve(n: usize) -> Vec<usize> {
    let mut r = vec![];
    for i in 1..=n {
        r.push(1 << i);
    }
    r
}

/*

Find the N-th Fibonacci prime number.

Input
The input file contains the number N (1≤N≤10).

Output
The output file should contain the N-th Fibonacci prime number.

Examples

Input #1
3

Answer #1
5

*/

fn main() {
    assert_eq!(solve(3), 5);

    for i in 1..=10 {
        println!("{}", solve(i));
    }
}

// https://oeis.org/A005478
fn solve(n: usize) -> u128 {
    let tab = [
        2,
        3,
        5,
        13,
        89,
        233,
        1597,
        28657,
        514229,
        433494437,
        2971215073,
        99194853094755497,
        1066340417491710595814572169,
        19134702400093278081449423917,
    ];

    if n == 0 || n > tab.len() {
        return 0;
    }
    return tab[n - 1];
}

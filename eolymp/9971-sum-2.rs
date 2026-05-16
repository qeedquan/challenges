/*

Calculate the sum of the first n terms in the sequence: 2,5,8,11,14,…

Input
A natural number n, where 1≤n≤100.

Output
Output a single integer — the sum of the first n terms of the sequence.

Examples

Input #1
7

Answer #1
77

*/

fn main() {
    let tab = vec![
        0, 2, 7, 15, 26, 40, 57, 77, 100, 126, 155, 187, 222, 260, 301, 345, 392, 442, 495, 551,
        610, 672, 737, 805, 876, 950, 1027, 1107, 1190, 1276, 1365, 1457, 1552, 1650, 1751, 1855,
        1962, 2072, 2185, 2301, 2420, 2542, 2667, 2795, 2926, 3060, 3197, 3337, 3480,
    ];

    assert_eq!(solve(7), 77);

    for i in 0..tab.len() {
        assert_eq!(solve(i), tab[i]);
    }

    for i in 0..10000 {
        assert_eq!(solve(i), solvebf(i));
    }
}

// https://oeis.org/A005449
fn solve(n: usize) -> usize {
    n * ((3 * n) + 1) / 2
}

fn solvebf(n: usize) -> usize {
    let mut r = 0;
    for i in 0..n {
        r += (3 * i) + 2;
    }
    r
}

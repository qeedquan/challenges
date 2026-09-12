/*

Find the number of sequences of length n consisting only of zeros and ones, in which there are no three consecutive ones.

Input
The length of the sequence n (1≤n≤10^5).

Output
Print the number of such sequences modulo 12345.

Examples

Input #1
1

Answer #1
2

Input #2
4

Answer #2
13

*/

fn main() {
    assert_eq!(solve(1), 2);
    assert_eq!(solve(4), 13);
}

fn solve(n: usize) -> usize {
    return tribonacci(n + 3);
}

// https://oeis.org/A000073
fn tribonacci(n: usize) -> usize {
    let (mut a, mut b, mut c, m) = (0, 0, 1, 12345);
    for _ in 0..n {
        (a, b, c) = (b, c, a + b + c % m);
    }
    return a;
}

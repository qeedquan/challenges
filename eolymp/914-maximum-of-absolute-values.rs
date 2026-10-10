/*

A sequence of real numbers is given. Compute the absolute values of these numbers. Find the maximum among these absolute values.

Input
The first line contains the number of elements n (n≤100) in the sequence.
The second line contains n real numbers — the elements of the sequence, each with absolute value not exceeding 100.

Output
Print the maximum among the absolute values of the given numbers, with 2 digits after the decimal point.

Examples

Input #1
5
6 7.5 2.1 2.0 0

Answer #1
7.50

Input #2
4
-76.45 7.5 -5.1 75.23

Answer #2
76.45

*/

fn main() {
    println!("{}", solve(&[6.0, 7.5, 2.1, 2.0, 0.0]));
    println!("{}", solve(&[-76.45, 7.5, -5.1, 75.23]));
}

fn solve(a: &[f64]) -> f64 {
    if a.len() == 0 {
        return 0.0;
    }

    let mut r = a[0].abs();
    for &x in &a[1..] {
        r = r.max(x.abs());
    }
    r
}

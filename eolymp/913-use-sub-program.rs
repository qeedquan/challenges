/*

Calculate the sum and product of N pairs of real numbers using the subroutine SumDob, which computes the sum and product of two real numbers.

Input
The first line contains a natural number N — the number of pairs.
Each of the next N lines contains two real numbers separated by a space. All input numbers have an absolute value not exceeding 100.

Output
Print N lines, each containing two numbers separated by a space: first the sum, then the product of the corresponding pair.
Print each result with exactly 4 digits after the decimal point.

Examples
Input #1
2
6 7.5
2.1 2.0

Answer #1
13.5000 45.0000
4.1000 4.2000

*/

fn main() {
    solve(6.0, 7.5);
    solve(2.1, 2.0);
}

fn solve(a: f64, b: f64) {
    println!("{:.4} {:.4}", a + b, a * b);
}

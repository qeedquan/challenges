/*

A number is called massive if it can be written in the form a^n, that is, a raised to the power of n.

You are given two massive numbers a^b and c^d, each written in the format "base^exponent". Your task is to compare these two numbers.

Input
Two massive numbers in the format "base^exponent" (1≤base,exponent≤1000). It is guaranteed that the two numbers are different.

Output
Print the greater of the two given massive numbers.

Examples

Input #1
3^100 2^150

Answer #1
3^100

Input #2
1^1000 2^1

Answer #2
2^1

*/

fn main() {
    assert_eq!(solve(3.0, 100.0, 2.0, 150.0), "3^100");
    assert_eq!(solve(1.0, 1000.0, 2.0, 1.0), "2^1");
}

fn solve(a: f64, b: f64, c: f64, d: f64) -> String {
    let x = b * a.ln();
    let y = d * c.ln();
    if x > y {
        return format!("{}^{}", a, b);
    }
    return format!("{}^{}", c, d);
}

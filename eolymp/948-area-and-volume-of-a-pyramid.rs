/*

Given a regular quadrilateral pyramid with base side d and lateral edge p, determine the total surface area and volume of the pyramid.

Input
The single line contains two integers separated by a space: the base side d and the lateral edge p. The input values do not exceed 100.

Output
Output the required total surface area and volume, separated by a space. The answer must be given to three decimal places.

Examples
Input #1
20 15

Answer #1
847.214 666.667

*/

#![allow(non_snake_case)]

fn main() {
    println!("{:.3?}", solve(20.0, 15.0));
}

fn solve(d: f64, p: f64) -> (f64, f64) {
    let h = (p * p - (d * d / 4.0)).sqrt();
    let H = (h * h - (d * d / 4.0)).sqrt();
    let s = (d * d) + (2.0 * h * d);
    let v = d * d * H / 3.0;
    (s, v)
}

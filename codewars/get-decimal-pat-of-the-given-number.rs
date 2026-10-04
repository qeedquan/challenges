/*

Write a function that returns only the decimal part of the given number.

You only have to handle valid numbers, not Infinity, NaN, or similar. Always return a positive decimal part.

Examples
getDecimal(2.4)  === 0.4
getDecimal(-0.2) === 0.2

*/

fn main() {
    println!("{}", decimal(2.4));
    println!("{}", decimal(-0.2));
}

fn decimal(x: f64) -> f64 {
    x.fract().abs()
}

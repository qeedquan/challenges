#![allow(non_snake_case)]

use std::f64::consts::PI;

fn main() {
    test(10.0, 250.0, 8.054);
    test(20.0, 2500.0, 14.775);
    test(25.0, 7000.0, 13.115);
    test(50.0, 50000.0, 30.901);
}

fn test(D: f64, V: f64, R: f64) {
    let X = solve(D, V);
    println!("{}", X);
    assert_eq!((X - R).abs() < 1e-3, true);
}

fn solve(D: f64, V: f64) -> f64 {
    ((D * D * D) - (6.0 * V / PI)).cbrt()
}

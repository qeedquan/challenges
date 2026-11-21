/*

Given a positive integer N, return the largest integer k such that 3^k < N.

For example,

largest_power(3) == 0
largest_power(4) == 1

You may assume that the input to your function is always a positive integer.

*/

fn main() {
    assert_eq!(largest_power(3), 0);
    assert_eq!(largest_power(4), 1);
    assert_eq!(largest_power(27), 2);
    assert_eq!(largest_power(30), 3);
}

fn largest_power(n: usize) -> usize {
    let x = n as f64;
    let r = (x.log10() / 3f64.log10()).ceil() - 1.0;
    r as usize
}

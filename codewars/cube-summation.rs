/*

Write a function cubeSum(n, m) that will calculate a sum of cubes of numbers in a given range, starting from the smaller (but not including it) to the larger (including). The first argument is not necessarily the larger number.

If both numbers are the same, then the range is empty and the result should be 0.

Examples:

cubeSum(2,3); // => 3^3 = 27
cubeSum(3,2); // => 3^3 = 27
cubeSum(0,4); // => 1^3+2^3+3^3+4^3 = 100
cubeSum(17, 14); // => 15^3+16^3+17^3 = 12384
cubeSum(9, 9); // => 0

*/

fn main() {
    assert_eq!(cubesum(2, 3), 27);
    assert_eq!(cubesum(3, 2), 27);
    assert_eq!(cubesum(0, 4), 100);
    assert_eq!(cubesum(17, 14), 12384);
    assert_eq!(cubesum(9, 9), 0);
    assert_eq!(cubesum(5, 0), 225);
}

fn cubesum(mut n: isize, mut m: isize) -> isize {
    if n > m {
        (n, m) = (m, n);
    }
    return seq(m) - seq(n);
}

// https://oeis.org/A000537
fn seq(n: isize) -> isize {
    if n < 0 {
        return 0;
    }
    let x = n * (n + 1) / 2;
    return x * x;
}

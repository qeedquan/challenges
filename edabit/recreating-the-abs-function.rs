/*

The Math.abs() function returns the absolute value of a number. This means that it returns a number's positive value. You can think of it as the distance away from zero.

Create a function that recreates this functionality.

Examples
absolute(-1.217197940) ➞ 1.21719794

absolute(-12.1320) ➞ 12.132
 
absolute(-544.0) ➞ 544

absolute(4666) ➞ 4666

absolute(-3.14) ➞ 3.14

absolute(250) ➞ 250

Notes
Tests will only include valid numbers.
Don't use the Math.abs() function (it will defeat the purpose of the challenge).

*/

fn main() {
    assert_eq!(absolute(-1.217197940), 1.217197940);
    assert_eq!(absolute(-12.1320), 12.132);
    assert_eq!(absolute(-544.0), 544.0);
    assert_eq!(absolute(4666.0), 4666.0);
    assert_eq!(absolute(-3.14), 3.14);
    assert_eq!(absolute(250.0), 250.0);
}

fn absolute(x: f64) -> f64 {
    if x < 0.0 {
        -x
    } else {
        x
    }
}

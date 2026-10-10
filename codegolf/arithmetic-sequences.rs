/*

An arithmetic sequence is a sequence of numbers of the form a,a+n,a+2n,a+3n, etc. In this case, a and n will both be either integers or decimals.

Given two inputs, a, n, and a top number value, return a list of numbers where the last term is less than or equal to the top number value.

The input can be formatted in any way, as well as the output.

The catch to this problem is dealing with floating point arithmetic errors.
For example, 0.1 + 0.3 * 3 is 1, however this will display 0.99999999999... if you simply go 0.1 + 0.3 * 3. We want 1, not 0.99999999999...

Test Cases
a=2, n=3, top=10: [2, 5, 8]
a=3, n=1.5, top=12: [3, 4.5, 6, 7.5, 9, 10.5, 12]
a=3.14159, n=2.71828, top=10: [3.14159, 5.85987, 8.57815]
a=0.1, n=0.3, top=2: [0.1, 0.4, 0.7, 1, 1.3, 1.6, 1.9]

Shortest code wins. Good luck!

*/

use std::cmp::*;
use std::ops::*;

fn main() {
    println!("{:?}", seq(2, 3, 10));
    println!("{:?}", seq(3.0, 1.5, 12.0));
    println!("{:?}", seq(3.14159, 2.71828, 10.0));
    println!("{:?}", seq(0.1, 0.3, 2.0));
}

fn seq<T: PartialOrd + AddAssign + Copy>(mut a: T, n: T, top: T) -> Vec<T> {
    let mut r = vec![];
    while a <= top {
        r.push(a);
        a += n;
    }
    r
}

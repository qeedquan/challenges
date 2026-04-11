/*

Ugly numbers are numbers whose only prime factors are 2, 3 or 5. The sequence
1, 2, 3, 4, 5, 6, 8, 9, 10, 12, 15, ...
shows the first 11 ugly numbers. By convention, 1 is included.
Write a program to find and print the 1500’th ugly number.

Input
There is no input to this program.

Output
Output should consist of a single line as shown below, with ‘<number>’ replaced by the number
computed.

Sample Output
The 1500'th ugly number is <number>.

*/

use std::cmp::min;

fn main() {
    let u = uglysieve(1500);
    println!("{}", u[1499]);
}

fn uglysieve(n: usize) -> Vec<usize> {
    let mut u = vec![0; n];
    if n < 1 {
        return u;
    }

    let (mut i2, mut i3, mut i5) = (0, 0, 0);
    let (mut n2, mut n3, mut n5) = (2, 3, 5);
    u[0] = 1;
    for i in 1..n {
        u[i] = min(n2, min(n3, n5));
        if u[i] == n2 {
            (n2, i2) = (u[i2 + 1] * 2, i2 + 1);
        }
        if u[i] == n3 {
            (n3, i3) = (u[i3 + 1] * 3, i3 + 1);
        }
        if u[i] == n5 {
            (n5, i5) = (u[i5 + 1] * 5, i5 + 1);
        }
    }
    return u;
}

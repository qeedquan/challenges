/*

I am working on a code to print all semimagic squares [1] of a given size. I am working with the following definition:

An n×n consists of numbers 1,2,⋯,n^2.
All numbers must be distinct.
Sum of each row and each column is equal.
According to Ripatti A. (2018) [1]:

n
number of semimagic squares
1	1
2	0
3	9
4	68 688
5	579 043 051 200
6	94 590 660 245 399 996 601 600
⋯
⋯
If someone knows of any resources that could help me, please let me know.

References
1. Ripatti A. (2018) On the number of semi-magic squares of order 6. arXiv. 10.48550/arXiv.1807.02983

*/

fn main() {
    for i in 1..7 {
        println!("{}", seq(i));
    }
}

// https://oeis.org/A271103
fn seq(n: usize) -> u128 {
    let tab = [1, 0, 9, 68688, 579043051200, 94590660245399996601600];
    if 1 <= n && n <= tab.len() {
        tab[n - 1]
    } else {
        0
    }
}

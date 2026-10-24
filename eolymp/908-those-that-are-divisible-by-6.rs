/*

For n integers, find the number and the sum of positive integers that are divisible by 6.

Input
The first line contains the number of integers n (0<n≤100).The next line contains n integers, each of which does not exceed 10000 in absolute value.

Output
Print the number of such integers and their sum.

Examples

Input #1
3
12 15 18

Answer #1
2 30

*/

fn main() {
    assert_eq!(solve(&[12, 15, 18]), (2, 30));
}

fn solve(a: &[isize]) -> (isize, isize) {
    let (mut s, mut n) = (0, 0);
    for &x in a {
        if x % 6 == 0 && x > 0 {
            s += x;
            n += 1;
        }
    }
    (n, s)
}

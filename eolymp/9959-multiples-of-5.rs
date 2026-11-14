/*

Given an array of n integers, print all numbers in the array that are divisible by 5, in reverse order. If no such numbers exist, output NO.

Input
The first line contains an integer n (1≤n≤100). The second line contains n integers, each with an absolute value not exceeding 100.

Output
On the first line, print the count of numbers divisible by 5. On the second line, print these numbers in reverse order. If there are no numbers divisible by 5, output NO.

Examples
Input #1
7
1 3 -5 0 -15 7 8

Answer #1
3
-15 0 -5

*/

fn main() {
    assert_eq!(solve(&[1, 3, -5, 0, -15, 7, 8]), vec![-15, 0, -5]);
}

fn solve(a: &[isize]) -> Vec<isize> {
    let mut r = vec![];
    for i in (0..a.len()).rev() {
        if a[i] % 5 == 0 {
            r.push(a[i]);
        }
    }
    r
}

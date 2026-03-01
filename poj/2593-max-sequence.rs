/*

Description

Give you N integers a1, a2 ... aN (|ai| <=1000, 1 <= i <= N).

S = [Max 1 <= i <= j < p <= q <= N] Sum[t=i, j] a[t] + Sum[t=p, q] a[t]

You should output S.

Input

The input will consist of several test cases. For each test case, one integer N (2 <= N <= 100000) is given in the first line. Second line contains N integers. The input is terminated by a single line with N = 0.

Output

For each test of the input, print a line containing S.

Sample Input

5
-5 9 -5 11 20
0

Sample Output

40
Source

POJ Monthly--2005.08.28,Li Haoyuan

*/

use std::cmp::*;

fn main() {
    assert_eq!(maximize(vec![-5, 9, -5, 11, 20]), 40);
    assert_eq!(maximize(vec![1, 2, 3, 4, 5]), 15);
    assert_eq!(maximize(vec![56, -4, 6, -6, -3, 5, 1, 54, 31, 54]), 203);
}

fn maximize(a: Vec<isize>) -> isize {
    let n = a.len();
    if n == 0 {
        return 0;
    }

    let (mut m, mut s, mut p) = (isize::MIN, 0, vec![]);
    for i in 0..n {
        s += a[i];
        m = max(m, s);
        p.push(m);
        s = max(s, 0);
    }

    let (mut m, mut s, mut i) = (isize::MIN, 0, n - 1);
    while i > 0 {
        s += a[i];
        m = max(m, s + p[i - 1]);
        s = max(s, 0);
        i -= 1;
    }

    return m;
}

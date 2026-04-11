/*

Given a sequence of integers S = {S1 , S2 , . . . , Sn }, you should determine what is the value of the
maximum positive product involving consecutive terms of S. If you cannot find a positive sequence,
you should consider 0 as the value of the maximum product.

Input
Each test case starts with 1 ≤ N ≤ 18, the number of elements in a sequence. Each element Si is
an integer such that −10 ≤ Si ≤ 10. Next line will have N integers, representing the value of each
element in the sequence. There is a blank line after each test case. The input is terminated by end of
file (EOF).

Output
For each test case you must print the message: ‘Case #M : The maximum product is P .’, where
M is the number of the test case, starting from 1, and P is the value of the maximum product. After
each test case you must print a blank line.

Sample Input
3
2 4 -3
5
2 5 -1 2 -1

Sample Output
Case #1: The maximum product is 8.
Case #2: The maximum product is 20.

*/

use std::cmp::max;

fn main() {
    assert_eq!(max_product(&[2, 4, -3]), 8);
    assert_eq!(max_product(&[2, 5, -1, 2, -1]), 20);
}

fn max_product(a: &[isize]) -> isize {
    let mut n = 0;
    let mut p = 1;
    let mut r = 0;
    for &v in a {
        p *= v;
        if p == 0 {
            n = 0;
            p = 1;
        } else if p > 0 {
            r = max(r, p);
        } else {
            if n != 0 {
                r = max(r, p / n);
            } else {
                n = p;
            }
            n = max(n, p);
        }
    }
    r
}

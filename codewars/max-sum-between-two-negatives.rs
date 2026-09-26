/*

Task
You have a list of integers. The task is to return the maximum sum of the elements located between two negative elements. No negative element should be present in the sum. If there is no such sum: -1 for Python, C++, JavaScript, Java, CoffeeScript and COBOL, Nothing for Haskell, None for Rust.

Example 1
[4, -1, 6, -2, 3, 5, -7, 7] -> 8
     ^      ^         ^
Sum between -1 and -2 is 6, between -2 and -7 is 3 + 5 = 8. It's also not 14 (between -1 and -7), because this includes a negative number (-2).

Example 2
[4, -1, -2] -> 0
     ^   ^
There is nothing between -1 and -2, so return 0.

*/

use std::cmp::max;

fn main() {
    assert_eq!(msn(&vec![4, -1, 6, -2, 3, 5, -7, 7]), 8);
    assert_eq!(msn(&vec![4, -1, -2]), 0);
}

fn msn(a: &Vec<isize>) -> isize {
    let mut r = 0;
    let mut i = 0;
    let n = a.len();
    while i < n {
        if a[i] >= 0 {
            i += 1;
            continue;
        }

        let mut s = 0;
        let mut j = i + 1;
        while j < n && a[j] >= 0 {
            s += a[j];
            j += 1;
        }
        r = max(r, s);
        i = j;
    }
    r
}

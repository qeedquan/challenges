/*

Task
Given two positive integers m (width) and n (height), fill a two-dimensional list (or array) of size m-by-n in the following way:

(1) All the elements in the first and last row and column are 1.

(2) All the elements in the second and second-last row and column are 2, excluding the elements from step 1.

(3) All the elements in the third and third-last row and column are 3, excluding the elements from the previous steps.

And so on ...

Examples
Given m = 5, n = 8, your function should return

[[1, 1, 1, 1, 1],
 [1, 2, 2, 2, 1],
 [1, 2, 3, 2, 1],
 [1, 2, 3, 2, 1],
 [1, 2, 3, 2, 1], 
 [1, 2, 3, 2, 1],
 [1, 2, 2, 2, 1],
 [1, 1, 1, 1, 1]]

Given m = 10, n = 9, your function should return

[[1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
 [1, 2, 2, 2, 2, 2, 2, 2, 2, 1],
 [1, 2, 3, 3, 3, 3, 3, 3, 2, 1], 
 [1, 2, 3, 4, 4, 4, 4, 3, 2, 1], 
 [1, 2, 3, 4, 5, 5, 4, 3, 2, 1], 
 [1, 2, 3, 4, 4, 4, 4, 3, 2, 1], 
 [1, 2, 3, 3, 3, 3, 3, 3, 2, 1], 
 [1, 2, 2, 2, 2, 2, 2, 2, 2, 1], 
 [1, 1, 1, 1, 1, 1, 1, 1, 1, 1]]

*/

use std::cmp::min;

fn main() {
    assert_eq!(
        r#box(5, 8),
        vec![
            [1, 1, 1, 1, 1],
            [1, 2, 2, 2, 1],
            [1, 2, 3, 2, 1],
            [1, 2, 3, 2, 1],
            [1, 2, 3, 2, 1],
            [1, 2, 3, 2, 1],
            [1, 2, 2, 2, 1],
            [1, 1, 1, 1, 1]
        ]
    );

    assert_eq!(
        r#box(10, 9),
        vec![
            [1, 1, 1, 1, 1, 1, 1, 1, 1, 1],
            [1, 2, 2, 2, 2, 2, 2, 2, 2, 1],
            [1, 2, 3, 3, 3, 3, 3, 3, 2, 1],
            [1, 2, 3, 4, 4, 4, 4, 3, 2, 1],
            [1, 2, 3, 4, 5, 5, 4, 3, 2, 1],
            [1, 2, 3, 4, 4, 4, 4, 3, 2, 1],
            [1, 2, 3, 3, 3, 3, 3, 3, 2, 1],
            [1, 2, 2, 2, 2, 2, 2, 2, 2, 1],
            [1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
        ]
    );
}

fn r#box(m: usize, n: usize) -> Vec<Vec<usize>> {
    let mut r = vec![];
    for i in 0..n {
        let mut v = vec![];
        for j in 0..m {
            v.push(1 + min(min(i, n - i - 1), min(j, m - j - 1)));
        }
        r.push(v);
    }
    r
}

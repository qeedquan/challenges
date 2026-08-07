/*

Consider the number triangle below, in which each number is equal to the number above plus the number to the left. If there is no number above, assume it's a 0.

1
1 1
1 2 2
1 3 5 5
1 4 9 14 14
The triangle has 5 rows and the sum of the last row is sum([1,4,9,14,14]) = 42.

You will be given an integer n and your task will be to return the sum of the last row of a triangle of n rows.

In the example above:

solve(5) = 42
More examples in test cases. Good luck!

Note
This kata uses native arbitrary precision integer numbers ( BigInt, 1n ).
Unfortunately, the testing framework and even native JSON do not fully support them yet.
console.log(1n) and (1n).toString() work and can be used for debugging.

We apologise for the inconvenience.

*/

use std::cmp::*;

fn main() {
    let tab = vec![
        1,
        1,
        2,
        5,
        14,
        42,
        132,
        429,
        1430,
        4862,
        16796,
        58786,
        208012,
        742900,
        2674440,
        9694845,
        35357670,
        129644790,
        477638700,
        1767263190,
        6564120420,
        24466267020,
        91482563640,
        343059613650,
        1289904147324,
        4861946401452,
        18367353072152,
        69533550916004,
        263747951750360,
        1002242216651368,
        3814986502092304,
    ];

    for i in 0..tab.len() {
        assert_eq!(catalan(i as i128), tab[i]);
    }
}

// https://oeis.org/A000108
fn catalan(n: i128) -> i128 {
    binomial(2 * n, n) / (n + 1)
}

fn binomial(n: i128, mut k: i128) -> i128 {
    if k < 0 || k > n {
        return 0;
    }
    if k == 0 || k == n {
        return 1;
    }

    k = min(k, n - k);
    let mut c = 1;
    for i in 0..k {
        c = c * (n - i) / (i + 1);
    }
    return c;
}

/*

Consider a sequence `u` where u is defined as follows:

1. The number `u(0) = 1` is the first one in `u`.
2. For each `x` in `u`, then `y = 2 * x + 1` and `z = 3 * x + 1` must be in `u` too.
3. There are no other numbers in `u`.

Ex:
`u = [1, 3, 4, 7, 9, 10, 13, 15, 19, 21, 22, 27, ...]`

1 gives 3 and 4, then 3 gives 7 and 10, 4 gives 9 and 13, then 7 gives 15 and 22 and so on...

#### Task:

Given parameter `n` the function `dbl_linear` (or dblLinear...) returns the element `u(n)` of
the ordered (with <) sequence `u` (so, there are no duplicates).

#### Example:

`dbl_linear(10) should return 22`

#### Note:

Focus attention on efficiency

*/

use std::cmp::min;

fn main() {
    let tab = vec![
        1, 3, 4, 7, 9, 10, 13, 15, 19, 21, 22, 27, 28, 31, 39, 40, 43, 45, 46, 55, 57, 58, 63, 64,
        67, 79, 81, 82, 85, 87, 91, 93, 94, 111, 115, 117, 118, 121, 127, 129, 130, 135, 136, 139,
        159, 163, 165, 166, 171, 172, 175, 183, 187, 189, 190, 193, 202, 223, 231, 235, 237,
    ];

    let x = gen(100);
    let x = &x[1..];
    assert_eq!(x[10], 22);
    assert_eq!(x[20], 57);
    assert_eq!(x[30], 91);
    assert_eq!(x[50], 175);
    for i in 0..tab.len() {
        assert_eq!(x[i], tab[i]);
    }
}

// https://oeis.org/A002977
fn gen(n: usize) -> Vec<usize> {
    let mut i2 = 1;
    let mut i3 = 1;

    let mut r = vec![0; (3 * n) + 1];
    r[1] = 1;
    for i in 2..=n {
        let x2 = (2 * r[i2]) + 1;
        let x3 = (3 * r[i3]) + 1;
        r[i] = min(x2, x3);
        if r[i] == x2 {
            i2 += 1;
        }
        if r[i] == x3 {
            i3 += 1;
        }
    }
    r.resize(n, 0);
    r
}

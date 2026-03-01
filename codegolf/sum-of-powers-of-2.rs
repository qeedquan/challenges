/*

The Challenge

Given an integer input x where 1 <= x <= 255, return the results of powers of two that when summed give x.

Examples

Given the input:

86
Your program should output:

64 16 4 2

Input:

240

Output:

128 64 32 16

Input:

1

Output:

1

Input:

64

Output:

64

The output may contain zeros if the certain power of two is not present in the sum.

For example, input 65 may output 0 64 0 0 0 0 0 1.

Scoring

This is code-golf, so the shortest answer in each language wins.

*/

fn main() {
    assert_eq!(decompose(86), vec![64, 16, 4, 2]);
    assert_eq!(decompose(240), vec![128, 64, 32, 16]);
    assert_eq!(decompose(1), vec![1]);
    assert_eq!(decompose(64), vec![64]);
    assert_eq!(decompose(65), vec![64, 1]);
    assert_eq!(decompose(255), vec![128, 64, 32, 16, 8, 4, 2, 1]);
}

fn decompose(mut x: usize) -> Vec<usize> {
    if x == 0 {
        return vec![0];
    }

    let mut r = vec![];
    while x != 0 {
        let m = 1 << (x.trailing_zeros() as usize);
        x &= !m;
        r.push(m);
    }
    r.reverse();

    r
}

/*

Given a permutation p, find its inverse p^-1.

Input
The first line contains the order n (0<n≤20000) of the permutation p. The second line contains the permutation p.

Output
Print the inverse permutation p^−1.

Examples
Input #1
3
2 3 1

Answer #1
3 1 2

*/

fn main() {
    assert_eq!(solve(&[2, 3, 1]), vec![3, 1, 2]);
}

fn solve(p: &[usize]) -> Vec<usize> {
    let mut r = vec![0; p.len()];
    for i in 0..p.len() {
        r[p[i] - 1] = i + 1;
    }
    r
}

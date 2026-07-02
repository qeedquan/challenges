/*

Find all n-digit numbers with sum of digits equal to s.

Input
Two integers n (1≤n≤6) and s (0≤s≤54).

Output
Print all n-digit numbers in increasing order whose sum of digits equals s. Print each number in a separate line.

Examples

Input #1
2 7

Answer #1
16
25
34
43
52
61
70

Input #2
3 25

Answer #2
799
889
898
979
988
997

Input #3
1 6

Answer #3
6

*/

fn main() {
    assert_eq!(solve(2, 7), vec![16, 25, 34, 43, 52, 61, 70]);
    assert_eq!(solve(3, 25), vec![799, 889, 898, 979, 988, 997]);
    assert_eq!(solve(1, 6), vec![6]);
}

fn solve(n: usize, s: usize) -> Vec<usize> {
    let mut r = vec![];
    if n == 0 {
        return r;
    }

    let a = 10usize.pow((n - 1) as u32);
    let b = a * 10;
    for i in a..b {
        if digsum(i) == s {
            r.push(i);
        }
    }
    r
}

fn digsum(mut n: usize) -> usize {
    let mut r = 0;
    while n > 0 {
        r += n % 10;
        n /= 10;
    }
    r
}

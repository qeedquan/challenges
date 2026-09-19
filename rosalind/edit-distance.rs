/*

Problem
Given two strings s and t (of possibly different lengths), the edit distance dE(s,t) is the minimum number of edit operations needed to transform s into t,
where an edit operation is defined as the substitution, insertion, or deletion of a single symbol.

The latter two operations incorporate the case in which a contiguous interval is inserted into or deleted from a string; such an interval is called a gap.
For the purposes of this problem, the insertion or deletion of a gap of length k still counts as k distinct edit operations.

Given: Two protein strings s and t in FASTA format (each of length at most 1000 aa).

Return: The edit distance dE(s,t).

Sample Dataset
>Rosalind_39
PLEASANTLY
>Rosalind_11
MEANLY
Sample Output
5

*/

use std::cmp::min;

fn main() {
    assert_eq!(edit("PLEASANTLY", "MEANLY"), 5);
}

fn edit(s: &'static str, t: &'static str) -> usize {
    let s = s.as_bytes();
    let t = t.as_bytes();
    let m = s.len();
    let n = t.len();

    let mut d = vec![vec![0; n + 1]; m + 1];
    for i in 1..m + 1 {
        d[i][0] = i;
    }
    for j in 1..n + 1 {
        d[0][j] = j;
    }

    for i in 1..m + 1 {
        for j in 1..n + 1 {
            if s[i - 1] == t[j - 1] {
                d[i][j] = d[i - 1][j - 1];
            } else {
                d[i][j] = min(min(d[i][j - 1] + 1, d[i - 1][j] + 1), d[i - 1][j - 1] + 1);
            }
        }
    }
    d[m][n]
}

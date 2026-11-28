/*

Description

The Stirling number of the second kind S(n, m) stands for the number of ways to partition a set of n things into m nonempty subsets. For example, there are seven ways to split a four-element set into two parts:

{1, 2, 3} U {4}, {1, 2, 4} U {3}, {1, 3, 4} U {2}, {2, 3, 4} U {1}

{1, 2} U {3, 4}, {1, 3} U {2, 4}, {1, 4} U {2, 3}.


There is a recurrence which allows to compute S(n, m) for all m and n.

S(0, 0) = 1; S(n, 0) = 0 for n > 0; S(0, m) = 0 for m > 0;

S(n, m) = m S(n - 1, m) + S(n - 1, m - 1), for n, m > 0.


Your task is much "easier". Given integers n and m satisfying 1 <= m <= n, compute the parity of S(n, m), i.e. S(n, m) mod 2.


Example

S(4, 2) mod 2 = 1.



Task

Write a program which for each data set:
reads two positive integers n and m,
computes S(n, m) mod 2,
writes the result.

Input

The first line of the input contains exactly one positive integer d equal to the number of data sets, 1 <= d <= 200. The data sets follow.

Line i + 1 contains the i-th data set - exactly two integers ni and mi separated by a single space, 1 <= mi <= ni <= 10^9.

Output

The output should consist of exactly d lines, one line for each data set. Line i, 1 <= i <= d, should contain 0 or 1, the value of S(ni, mi) mod 2.

Sample Input

1
4 2

Sample Output

1
Source

Central Europe 2001

*/

fn main() {
    assert_eq!(stirling2(4, 2) & 1, 1);
}

// https://oeis.org/A008277
// https://oeis.org/A166280
fn stirling2(n: isize, m: isize) -> isize {
    if n == 0 && m == 0 {
        return 1;
    }
    if n <= 0 || m <= 0 {
        return 0;
    }
    return (m * stirling2(n - 1, m)) + stirling2(n - 1, m - 1);
}

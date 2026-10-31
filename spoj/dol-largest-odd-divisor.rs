/*

Given a non-negative integers N. You have to find the largest odd divisor of N.

Input
Input starts with an integer T (1 ≤ T ≤ 5000) denoting the number of test cases. Each test case contains an integer N (1 ≤ N ≤ 10^12).

Output
For each test case print the case number and the largest odd divisor of N.

Example
Input:
2
2
10

Output:
Case 1: 1
Case 2: 5

Problem Setter: Md Abdul Alim, Dept. of Computer Science, Bangladesh University of Business & Technology

*/

fn main() {
    assert_eq!(solve(2), 1);
    assert_eq!(solve(10), 5);
}

fn solve(mut n: usize) -> usize {
    while (n & 1) == 0 {
        n >>= 1;
    }
    n
}

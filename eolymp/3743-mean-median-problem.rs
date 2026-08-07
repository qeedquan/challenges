/*

The mean of three integers a, b and c is (a+b+c)/3.
The median of three integers is the middle number if they are arranged in non-decreasing order.

Input
Each test case is given in a single line that contains two integers a and b (1≤a≤b≤10^9).
The last test case is followed by a line containing two zeros, which should not be processed.

Output
For each test case, output one line containing the minimum possible integer c such that the mean and the median of a, b and c are equal.

Examples

Input #1
1 2
6 10
1 1000000000
0 0

Answer #1
0
2
-999999998

*/

fn main() {
    assert_eq!(solve(1, 2), 0);
    assert_eq!(solve(6, 10), 2);
    assert_eq!(solve(1, 1000000000), -999999998);
}

fn solve(a: isize, b: isize) -> isize {
    (2 * a) - b
}

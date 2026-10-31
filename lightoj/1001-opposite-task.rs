/*

This problem gives you a flavor of the concept of a special judge. That means the judge is smart enough to verify your code even though it may print different results. In this problem, you are asked to find the opposite task of the previous problem.

To be specific, I have two computers where I stored my problems. Now I know the total number of problems is n. There are no duplicate problems, and there can be at most 10 problems in each computer. You have to find the number of problems on each of the computers.

Since there can be multiple solutions. Any valid solution will do.

Input
Input starts with an integer T (≤ 25), denoting the number of test cases.

Each case starts with a line containing an integer n (0 ≤ n ≤ 20) denoting the total number of problems.

Output
For each case, print the number of problems stored in each computer in a single line. A single space should separate the non-negative integers.

Sample
Input	Output
3
10
7
7

0 10
0 7
1 6

*/

fn main() {
    assert_eq!(solve(10), (5, 5));
    assert_eq!(solve(7), (3, 4));
}

fn solve(n: isize) -> (isize, isize) {
    if n < 0 || n > 20 {
        return (-1, -1);
    }
    return (n / 2, (n / 2) + (n % 2));
}

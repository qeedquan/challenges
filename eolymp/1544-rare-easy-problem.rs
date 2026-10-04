/*

n is a random number, which, for some reason, is at least two digits.
John Doe, a nondescript man, performs an operation on n: he chops off the last digit to form a new number m, and then finds n−m.
This excites him in a hard-to-justify way.
He then tells you n−m.
Thrilled by the fascinating back-story behind this number, you make it your life's goal to figure out what n was.

Input
Input consists of multiple lines, one per case. Each line contains a single positive integer between 10 and 10^18 inclusive, giving the value of n−m.
Input is terminated by a line containing 0.

Output
For each case, print one line containing the possible values of n in sorted order. Separate consecutive numbers with a single space.

Examples

Input #1
18
0

Answer #1
19 20

*/

fn main() {
    assert_eq!(solve(18), vec![19, 20]);
}

fn solve(n: isize) -> Vec<isize> {
    let a = n % 9;
    let x = (n - a) / 9;
    let mut r = vec![];
    if a == 0 {
        r.push(10 * (x - 1) + 9);
    }
    r.push(10 * x + a);
    r
}

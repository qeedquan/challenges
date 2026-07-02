/*

The Stern–Brocot tree is an elegant method for constructing the set of all nonnegative fractions m/n, where m and n are relatively prime.
The idea is to start with two fractions and then repeatedly perform the following operation:

Insert a new fraction between every two adjacent fractions.

For example, the first step inserts a new fraction between the starting two.
The next step inserts two more, then four, and so on.
The entire structure can be viewed as an infinite binary tree, and the tree's upper levels look like this.

This construction preserves order, so the same fraction does not appear in more than one place.

In fact, the Stern–Brocot tree can be thought of as a number system that represents rational numbers, because each positive,
reduced fraction appears in the tree exactly once.
We use the letters L and R to indicate moving left or right as we descend from the root of the tree to a particular fraction;
thus, a string of Ls and Rs uniquely identifies a position in the tree. For example, LRRL means going left, then right, right, and left.
We can consider LRRL to represent a certain fraction. Every positive fraction corresponds to exactly one such string.

Technically, there is one exception: the fraction 1/1 corresponds to the empty string. We denote this by I, as it resembles 1 and stands for "identity".

In this problem, given a positive rational fraction, represent it in the Stern–Brocot number system.

Input
The input consists of multiple test cases.
Each test case consists of two relatively prime positive integers m and n.
The final test contains two ones and should not be processed.

Output
For each test case, output a line with the representation of the given fraction in the Stern–Brocot number system.

Examples
Input #1
5 7
878 323
1 1

Answer #1
LRRL
RRLRRLRLLLLRLRRR

*/

fn main() {
    assert_eq!(solve(5, 7), "LRRL");
    assert_eq!(solve(878, 323), "RRLRRLRLLLLRLRRR");
}

fn solve(mut m: isize, mut n: isize) -> String {
    let mut r = String::new();
    while m != n {
        if n > m {
            r.push('L');
            n -= m;
        } else {
            r.push('R');
            m -= n;
        }
    }
    r
}

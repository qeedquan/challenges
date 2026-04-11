/*

When shopping on Long Street, Michael usually parks his car at some random
location, and then walks to the stores he needs. Can you help Michael choose
a place to park which minimises the distance he needs to walk on his shopping
round?
Long Street is a straight line, where all positions are integer. You pay for
parking in a specific slot, which is an integer position on Long Street. Michael
does not want to pay for more than one parking though. He is very strong,
and does not mind carrying all the bags around.

Input
The first line of input gives the number of test cases, 1 ≤ t ≤ 100. There are two lines for each test
case. The first gives the number of stores Michael wants to visit, 1 ≤ n ≤ 20, and the second gives their
n integer positions on Long Street, 0 ≤ xi ≤ 99.

Output
Output for each test case a line with the minimal distance Michael must walk given optimal parking.

Sample Input
2
4
24 13 89 37
6
7 30 41 14 39 42

Sample Output
152
70

*/

use std::cmp::*;

fn main() {
    assert_eq!(parking(&[24, 13, 89, 37]), 152);
    assert_eq!(parking(&[7, 30, 41, 14, 39, 42]), 70);
}

fn parking(a: &[isize]) -> isize {
    let (mut l, mut r) = (isize::MAX, isize::MIN);
    for &x in a {
        l = min(l, x);
        r = max(r, x);
    }
    2 * (r - l)
}

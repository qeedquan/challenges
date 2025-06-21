/*

Description

Eva的家庭作业里有很多数列填空练习。填空练习的要求是：已知数列的前四项，填出第五项。因为已经知道这些数列只可能是等差或等比数列，她决定写一个程序来完成这些练习。

Input

第一行是数列的数目t（0 <= t <= 20）。以下每行均包含四个整数，表示数列的前四项。约定数列的前五项均为不大于10^5的自然数，等比数列的比值也是自然数。

Output

对输入的每个数列，输出它的前五项。

Sample Input

2
1 2 3 4
1 2 4 8

Sample Output

1 2 3 4 5
1 2 4 8 16

Source

POJ Monthly--2004.05.15 Null

*/

fn main() {
    assert_eq!(seq(1, 2, 3, 4), (1, 2, 3, 4, 5));
    assert_eq!(seq(1, 2, 4, 8), (1, 2, 4, 8, 16));
}

fn seq(a: isize, b: isize, c: isize, d: isize) -> (isize, isize, isize, isize, isize) {
    let e: isize;
    if (a - b == b - c) && (b - c == c - d) {
        e = (2 * d) - c;
    } else if c <= d {
        e = d * (d / c);
    } else {
        e = d / (c / d);
    }

    (a, b, c, d, e)
}

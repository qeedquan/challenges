/*

(This is OEIS A057531.)

Your task
Given a positive integer, n, find the nth number where the digit sum equals the number of factors

Explanation
For example, let's take 22:

Its factors are [1,2,11,22] (length: 4).

Its digit sum is 4.

This means that it is a number where the digit sum equals the number of factors.

The series
The first few terms of this series are:

[1,2,11,22,36,84,101,152,156,170]

Test cases
Note: these are 1-indexed. You may use 0-indexing.

Input  Output
1      1
2      2
3      11
4      22
5      36
10     170
20     444
30     828
40     1111
50     1548
100    3588

Clarifications
You may use either 0-indexing or 1-indexing
The sequence starts from 1, not from 0
The factors of a number include 1 and the number itself
Default sequence rules apply - you may output the first n terms, or the infinite sequence, or something else
This is code-golf, so shortest answer in bytes wins!

*/

fn main() {
    let tab = vec![
        1, 2, 11, 22, 36, 84, 101, 152, 156, 170, 202, 208, 225, 228, 288, 301, 372, 396, 441, 444,
        468, 516, 525, 530, 602, 684, 710, 732, 804, 828, 882, 952, 972, 1003, 1016, 1034, 1070,
        1072, 1106, 1111, 1164, 1236, 1304, 1308, 1425, 1472, 1476, 1521, 1524,
    ];

    assert_eq!(gen(tab.len()), tab);
}

// https://oeis.org/A057531
fn gen(n: usize) -> Vec<isize> {
    let mut r = vec![];
    let mut i = 1;
    while r.len() < n {
        if digitsum(i) == factors(i) {
            r.push(i);
        }
        i += 1;
    }
    r
}

fn digitsum(mut n: isize) -> isize {
    let mut r = 0;
    while n > 0 {
        r += n % 10;
        n /= 10;
    }
    r
}

fn factors(n: isize) -> isize {
    let mut c = 0;
    for i in 1..n + 1 {
        if n % i == 0 {
            c += 1;
        }
    }
    c
}

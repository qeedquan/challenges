/*

A square number is an integer number whose square root is also an integer. For example 1, 4, 81 are some square numbers.
Given two numbers a and b you will have to find out how many square numbers are there between a and b (inclusive).

Input
The input file contains at most 201 lines of inputs. Each line contains two integers a and b (0 < a ≤ b ≤ 100000).
Input is terminated by a line containing two zeroes. This line should not be processed.

Output
For each line of input produce one line of output. This line contains an integer which denotes how
many square numbers are there between a and b (inclusive).

Sample Input
1 4
1 10
0 0

Sample Output
2
3

*/

fn main() {
    assert_eq!(count(1, 4), 2);
    assert_eq!(count(1, 10), 3);
}

fn count(a: isize, b: isize) -> isize {
    let mut c = 0;
    for i in a..b + 1 {
        let s = (i as f64).sqrt() as isize;
        if i == s * s {
            c += 1;
        }
    }
    c
}

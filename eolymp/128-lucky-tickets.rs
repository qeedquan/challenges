/*

Count the number of lucky tickets for which the sum of the first three digits is equal to n.

A lucky ticket is a six-digit ticket in which the sum of the first three digits is equal to the sum of the last three digits.

Input
One positive integer n (n≤27).

Output
Print the number of lucky tickets.

Examples
Input #1
1

Answer #1
9

*/

fn main() {
    assert_eq!(solve(1), 9);

    for i in 0..=27 {
        println!("{}", solve(i));
    }
}

fn solve(n: usize) -> usize {
    let mut r = 0;
    for a in 0..10 {
        for b in 0..10 {
            for c in 0..10 {
                if a + b + c == n {
                    r += 1;
                }
            }
        }
    }
    r * r
}

/*

Task:
Consider a sequence where the first two numbers are 0 and 1 and the next number of the sequence is the sum of the previous 2 modulo 3. Write a function that finds the nth number of the sequence.

Constraints:
1 ≤ N ≤ 10^19
Example:
sequence(1);
0
sequence(2);
1
sequence(3);
1

*/

fn main() {
    assert_eq!(seq(1), 0);
    assert_eq!(seq(2), 1);
    assert_eq!(seq(3), 1);
    assert_eq!(seq(20), 2);
    assert_eq!(seq(41), 0);
    assert_eq!(seq(72), 1);
    assert_eq!(seq(82), 1);
    assert_eq!(seq(85), 0);
    assert_eq!(seq(90), 1);
    assert_eq!(seq(111), 2);
    assert_eq!(seq(117), 0);
    assert_eq!(seq(118), 2);
    assert_eq!(seq(148), 2);
    assert_eq!(seq(163), 1);
    assert_eq!(seq(5101394), 1);
}

// https://oeis.org/A082115
fn seq(n: usize) -> usize {
    [1, 0, 1, 1, 2, 0, 2, 2][n & 7]
}

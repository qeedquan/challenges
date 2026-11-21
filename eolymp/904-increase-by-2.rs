/*

A sequence of integers is given. Increase each of its non-negative elements by 2.

Input
The first line contains the number of elements n (n≤100). The second line contains the elements of the sequence, each with an absolute value not exceeding 100.

Output
Print n integers in one line: the new values of the sequence elements in the same order as given.

Examples

Input #1
4
1 2 3 -4

Answer #1
3 4 5 -4

*/

fn main() {
    assert_eq!(solve(&mut [1, 2, 3, -4]), &[3, 4, 5, -4]);
}

fn solve(a: &mut [isize]) -> &[isize] {
    for i in 0..a.len() {
        if a[i] >= 0 {
            a[i] += 2;
        }
    }
    a
}

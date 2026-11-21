/*

Write a function that takes an array / list of numbers and returns a number.

See the examples and try to guess the pattern:

(1, 2, 6, 1, 6, 3, 1, 9, 6) => 393
(1, 2, 3)                   =>   5
(0, 2, 3)                   =>   3
(1, 0, 3)                   =>   3
(3, 2)                      =>   6

*/

fn main() {
    assert_eq!(solve(&vec![1, 2, 6, 1, 6, 3, 1, 9, 6]), 393);
    assert_eq!(solve(&vec![1, 2, 3]), 5);
    assert_eq!(solve(&vec![1, 0, 3]), 3);
    assert_eq!(solve(&vec![3, 2]), 6);
}

fn solve(a: &Vec<isize>) -> isize {
    let mut r = 0;
    for i in 0..a.len() {
        if i & 1 != 0 {
            r *= a[i];
        } else {
            r += a[i];
        }
    }
    r
}

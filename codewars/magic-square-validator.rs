/*

In recreational mathematics, a magic square is an arrangement of distinct numbers (i.e., each number is used once), usually integers, in a square grid, where the numbers in each row, and in each column, and the numbers in the main and secondary diagonals, all add up to the same number, called the "magic constant."

For example, the following "square":

  4    9    2 -> 15
  3    5    7 -> 15
  8    1    6 -> 15
 /v    v    v \
15 15   15   15  15

A 3x3 magic square will have its sums always resulting to 15, this number is called the "magic constant" and changes according to the square size.

In this problem you will have to create a function that receives a 3x3 'square' and returns True if it is magic and False otherwise. The sum of rows, columns or diagonals should always equal 15.

For example, the above square will be passed like: [4, 9, 2, 3, 5, 7, 8, 1, 6] and the output should be True

[9, 4, 7, 3, 5, 2, 8, 6, 1] should return False

*/

use std::collections::HashMap;

fn main() {
    assert_eq!(is_magical(&[4, 9, 2, 3, 5, 7, 8, 1, 6]), true);
    assert_eq!(is_magical(&[9, 4, 7, 3, 5, 2, 8, 6, 1]), false);
    assert_eq!(is_magical(&[4, 9, 2, 3, 5, 7, 8, 1, 6]), true);
    assert_eq!(is_magical(&[4, 9, 2, 3, 5, 7, 8, 6, 1]), false);
    assert_eq!(is_magical(&[1, 2, 3, 4, 5, 6, 7, 8, 9]), false);
    assert_eq!(is_magical(&[9, 4, 7, 3, 5, 2, 8, 6, 1]), false);
    assert_eq!(is_magical(&[8, 1, 6, 3, 5, 7, 4, 9, 2]), true);
    assert_eq!(is_magical(&[1, 9, 5, 4, 8, 3, 7, 2, 6]), false);
}

fn is_magical(x: &[usize]) -> bool {
    if x.len() != 9 {
        return false;
    }

    let mut m = HashMap::new();
    for v in x {
        if let Some(_) = m.get(&v) {
            return false;
        }
        m.insert(v, true);
    }

    x[0] + x[1] + x[2] == 15
        && x[3] + x[4] + x[5] == 15
        && x[6] + x[7] + x[8] == 15
        && x[0] + x[3] + x[6] == 15
        && x[1] + x[4] + x[7] == 15
        && x[2] + x[5] + x[8] == 15
        && x[0] + x[4] + x[8] == 15
        && x[2] + x[4] + x[6] == 15
}

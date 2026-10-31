/*

Given a square matrix, rotate the original matrix 90 degrees clockwise... in place! This means that you are not allowed to build a rotated matrix and return it. Modify the original matrix using a temporary variable to swap elements and return it. You are allowed to use a couple scalar variables if needed.

Solutions similar to the following are correct, but not allowed for this kata:

def rotate_not_in_place(matrix):
  return [[row[i] for row in reversed(matrix)] for i in range(len(matrix))]
Esentially any method that involves generating a new matrix isn't allowed.

To sum up, given a square matrix of any size as an input:

  [[1, 2, 3],
  [4, 5, 6],
  [7, 8, 9]]
Modify the original matrix rotating it in place 90 degrees clockwise and return it:

  [[7, 4, 1],
  [8, 5, 2],
  [9, 6, 3]]

This problem is very googleable so I suggest trying it out without looking for help.

*/

fn main() {
    let mut m1 = vec![vec![1]];
    let mut m2 = vec![vec![1, 2], vec![3, 4]];
    let mut m3 = vec![vec![1, 2, 3], vec![4, 5, 6], vec![7, 8, 9]];

    let r1 = vec![vec![1]];
    let r2 = vec![vec![3, 1], vec![4, 2]];
    let r3 = vec![vec![7, 4, 1], vec![8, 5, 2], vec![9, 6, 3]];

    rot90(&mut m1);
    rot90(&mut m2);
    rot90(&mut m3);

    assert_eq!(m1, r1);
    assert_eq!(m2, r2);
    assert_eq!(m3, r3);
}

fn rot90(m: &mut Vec<Vec<isize>>) {
    let n = m.len();
    for i in 0..n / 2 {
        for j in i..n - 1 - i {
            let t = m[i][j];
            m[i][j] = m[n - 1 - j][i];
            m[n - 1 - j][i] = m[n - 1 - i][n - 1 - j];
            m[n - 1 - i][n - 1 - j] = m[j][n - 1 - i];
            m[j][n - 1 - i] = t;
        }
    }
}

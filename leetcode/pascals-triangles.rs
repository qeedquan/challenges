/*

Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
Example 2:

Input: numRows = 1
Output: [[1]]
 

Constraints:

1 <= numRows <= 30

*/

fn main() {
    assert_eq!(pascal(1), vec![vec![1]]);
    assert_eq!(
        pascal(5),
        vec![
            vec![1],
            vec![1, 1],
            vec![1, 2, 1],
            vec![1, 3, 3, 1],
            vec![1, 4, 6, 4, 1]
        ]
    );
}

fn pascal(n: usize) -> Vec<Vec<usize>> {
    if n == 0 {
        return vec![];
    }

    let mut m = vec![vec![]; n];
    for i in 0..n {
        m[i] = vec![0; i + 1];
    }

    m[0][0] = 1;
    for i in 1..n {
        for j in 0..i + 1 {
            if j == 0 || j == i {
                m[i][j] = m[i - 1][0];
            } else {
                m[i][j] = m[i - 1][j - 1] + m[i - 1][j];
            }
        }
    }

    return m;
}

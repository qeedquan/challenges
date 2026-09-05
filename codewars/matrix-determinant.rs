/*

Write a function that accepts a square matrix (N x N 2D array) and returns the determinant of the matrix.

How to take the determinant of a matrix -- it is simplest to start with the smallest cases:

A 1x1 matrix |a| has determinant a.

A 2x2 matrix [ [a, b], [c, d] ] or

|a  b|
|c  d|
has determinant: a*d - b*c.

The determinant of an n x n sized matrix is calculated by reducing the problem to the calculation of the determinants of n matrices ofn-1 x n-1 size.

For the 3x3 case, [ [a, b, c], [d, e, f], [g, h, i] ] or

|a b c|  
|d e f|  
|g h i|  
the determinant is: a * det(a_minor) - b * det(b_minor) + c * det(c_minor) where det(a_minor) refers to taking the determinant of the 2x2 matrix created by crossing out the row and column in which the element a occurs:

|- - -|
|- e f|
|- h i|  
Note the alternation of signs.

The determinant of larger matrices are calculated analogously, e.g. if M is a 4x4 matrix with first row [a, b, c, d], then:

det(M) = a * det(a_minor) - b * det(b_minor) + c * det(c_minor) - d * det(d_minor)

*/

fn main() {
    assert_eq!(det(&vec![vec![1]]), 1,);
    assert_eq!(det(&vec![vec![1, 3], vec![2, 5]]), -1);
    assert_eq!(
        det(&vec![vec![2, 5, 3], vec![1, -2, -1], vec![1, 3, 4]]),
        -20
    );
}

fn det(matrix: &Vec<Vec<isize>>) -> isize {
    minor(matrix, 0, &mut vec![false; matrix.len()])
}

fn minor(matrix: &Vec<Vec<isize>>, depth: usize, visited: &mut Vec<bool>) -> isize {
    let size = matrix.len();
    if size == 0 {
        return 0;
    }
    if depth >= size {
        return 1;
    }

    let mut sum = 0;
    let mut sign = 1;
    for i in 0..size {
        if !visited[i] {
            visited[i] = true;
            sum += sign * matrix[depth][i] * minor(matrix, depth + 1, visited);
            visited[i] = false;
            sign = -sign;
        }
    }
    sum
}

/*

You have a matrix 2×2 filled with distinct integers. You want your matrix to become beautiful. The matrix is beautiful if the following two conditions are satisfied:

in each row, the first element is smaller than the second element;
in each column, the first element is smaller than the second element.

You can perform the following operation on the matrix any number of times: rotate it clockwise by 90 degrees, so the top left element shifts to the top right cell, the top right element shifts to the bottom right cell, and so on:


Determine if it is possible to make the matrix beautiful by applying zero or more operations.

Input
The first line contains one integer t (1≤t≤1000) — the number of test cases.

Each test case consists of two lines. Each of those lines contains two integers — the elements of the corresponding row of the matrix. In each matrix, all four elements are distinct integers from 1 to 100.

Output
For each test case, print YES if the matrix can become beautiful, or NO otherwise. You may print each letter in any case (YES, yes, Yes will all be recognized as positive answer, NO, no and nO will all be recognized as negative answer).

Example

input
6
1 3
5 7
8 10
3 4
8 10
4 3
6 1
9 2
7 5
4 2
1 2
4 3

output
YES
YES
NO
YES
YES
NO

*/

type Mat2 = [[isize; 2]; 2];

fn main() {
    assert_eq!(beautifiable([[1, 3], [5, 7]]), true);
    assert_eq!(beautifiable([[8, 10], [3, 4]]), true);
    assert_eq!(beautifiable([[8, 10], [4, 3]]), false);
    assert_eq!(beautifiable([[6, 1], [9, 2]]), true);
    assert_eq!(beautifiable([[7, 5], [4, 2]]), true);
    assert_eq!(beautifiable([[1, 2], [4, 3]]), false);

    assert_eq!(beautifiable([[10, 13], [12, 42]]), true);
    assert_eq!(beautifiable([[4, 8], [6, 9]]), true);
    assert_eq!(beautifiable([[13, 37], [42, 69]]), true);

    assert_eq!(beautifiable([[1, 3], [7, 5]]), false);
    assert_eq!(beautifiable([[10, 3], [5, 12]]), false);
    assert_eq!(beautifiable([[13, 37], [69, 42]]), false);
}

fn beautifiable(m: Mat2) -> bool {
    let mut n = m;
    while !beautiful(n) {
        n = rot90(n);
        if m == n {
            return false;
        }
    }
    return true;
}

fn rot90(m: Mat2) -> Mat2 {
    [[m[1][0], m[0][0]], [m[1][1], m[0][1]]]
}

fn beautiful(m: Mat2) -> bool {
    if m[0][0] >= m[1][0] || m[1][0] >= m[1][1] {
        return false;
    }
    if m[0][0] >= m[0][1] || m[0][1] >= m[1][1] {
        return false;
    }
    return true;
}

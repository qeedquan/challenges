/*

Principal Diagonal -- The principal diagonal in a matrix identifies those elements of the matrix running from North-West to South-East.

Secondary Diagonal -- the secondary diagonal of a matrix identifies those elements of the matrix running from North-East to South-West.

For example:

matrix:             [1, 2, 3]
                    [4, 5, 6]
                    [7, 8, 9]

principal diagonal: [1, 5, 9]
secondary diagonal: [3, 5, 7]
Task
Your task is to find which diagonal is "larger": which diagonal has a bigger sum of their elements.

If the principal diagonal is larger, return "Principal Diagonal win!"
If the secondary diagonal is larger, return "Secondary Diagonal win!"
If they are equal, return "Draw!"
Note: You will always receive matrices of the same dimension.

*/

fn main() {
    assert_eq!(
        diagonal(&[&[2, 2, 2], &[4, 2, 6], &[8, 8, 2]]),
        "Secondary Diagonal win!"
    );

    assert_eq!(
        diagonal(&[&[2, 2, 2], &[4, 2, 6], &[1, 8, 2]]),
        "Principal Diagonal win!"
    );

    assert_eq!(diagonal(&[&[1, 2, 3], &[4, 5, 6], &[7, 8, 9]]), "Draw!");

    assert_eq!(
        diagonal(&[
            &[88, 2, 2, 5, 1, 1, 2, 2, 5, 1],
            &[4, 1, 6, 1, 1, 1, 2, 2, 1, 1],
            &[1, 8, 1, 6, 2, 1, 2, 1, 5, 1],
            &[1, 5, 2, 1, 2, 1, 1, 2, 5, 1],
            &[1, 8, 2, 6, 1, 1, 2, 2, 5, 1],
            &[1, 2, 2, 5, 1, 1, 2, 2, 5, 1],
            &[1, 2, 2, 1, 1, 1, 1, 2, 5, 1],
            &[1, 2, 1, 5, 1, 1, 2, 1, 5, 1],
            &[1, 1, 2, 5, 1, 1, 2, 2, 1, 1],
            &[88, 2, 2, 5, 1, 1, 2, 2, 5, 1]
        ]),
        "Draw!"
    );

    assert_eq!(
        diagonal(&[&[0, 0, 0], &[0, 0, 0], &[1, 0, 0]]),
        "Secondary Diagonal win!"
    );

    assert_eq!(
        diagonal(&[
            &[1, 2, 2, 5, 1],
            &[4, 1, 6, 1, 1],
            &[1, 8, 5, 6, 2],
            &[1, 5, 2, 1, 2],
            &[1, 8, 2, 6, 1],
        ]),
        "Secondary Diagonal win!"
    );

    assert_eq!(
        diagonal(&[&[0, 0, 0], &[0, 0, 0], &[0, 0, 1]]),
        "Principal Diagonal win!"
    );

    assert_eq!(
        diagonal(&[
            &[1, 2, 2, 5, 1, 1, 2, 2, 5, 15],
            &[4, 1, 6, 1, 1, 1, 2, 2, 1, 1],
            &[1, 8, 1, 6, 2, 1, 2, 1, 5, 1],
            &[1, 5, 2, 1, 2, 1, 1, 2, 5, 1],
            &[1, 8, 2, 6, 1, 1, 2, 2, 5, 1],
            &[1, 2, 2, 5, 1, 1, 2, 2, 5, 1],
            &[1, 2, 2, 1, 1, 1, 1, 2, 5, 1],
            &[1, 2, 1, 5, 1, 1, 2, 1, 5, 1],
            &[1, 1, 2, 5, 1, 1, 2, 2, 1, 1],
            &[1, 2, 2, 5, 1, 1, 2, 2, 5, 15],
        ]),
        "Draw!"
    );

    assert_eq!(
        diagonal(&[
            &[9, 2, 2, 5, 1, 1, 2, 2, 5, 9],
            &[4, 1, 6, 1, 1, 1, 2, 2, 1, 1],
            &[1, 8, 1, 6, 2, 1, 2, 1, 5, 1],
            &[1, 5, 2, 1, 2, 1, 1, 2, 5, 1],
            &[1, 8, 2, 6, 1, 1, 2, 2, 5, 1],
            &[1, 2, 2, 5, 1, 1, 2, 2, 5, 1],
            &[1, 2, 2, 1, 1, 1, 1, 2, 5, 1],
            &[1, 2, 1, 5, 1, 1, 2, 1, 5, 1],
            &[1, 1, 2, 5, 1, 1, 2, 2, 1, 1],
            &[9, 2, 2, 5, 1, 1, 2, 2, 5, 9],
        ]),
        "Draw!"
    );
}

fn diagonal(m: &[&[isize]]) -> &'static str {
    let (mut l, mut r, n) = (0, 0, m.len());
    for i in 0..n {
        r += m[i][i];
        l += m[i][n - i - 1];
    }
    if r == l {
        return "Draw!";
    }
    if r > l {
        return "Principal Diagonal win!";
    }
    return "Secondary Diagonal win!";
}

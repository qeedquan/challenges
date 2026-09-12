/*

Midpoint Sum
For a given list of integers, return the index of the element where the sums of the integers to the left and right of the current element are equal.

Ex:

ints = [4, 1, 7, 9, 3, 9]
# Since 4 + 1 + 7 = 12 and 3 + 9 = 12, the returned index would be 3

ints = [1, 0, -1]
# Returns None/nil/undefined/etc (depending on the language) as there
# are no indices where the left and right sums are equal
Here are the 2 important rules:

The element at the index to be returned is not included in either of the sum calculations!
Both the first and last index cannot be considered as a "midpoint" (So None for [X] and [X, X])

*/

fn main() {
    assert_eq!(midpoint(&[1, 0, -1]), -1);
    assert_eq!(midpoint(&[4, 1, 7, 9, 3, 9]), 3);
    assert_eq!(midpoint(&[1, 0, 1]), 1);
    assert_eq!(midpoint(&[9, 0, 1, 2, 3, 4]), 2);
    assert_eq!(midpoint(&[0, 0, 4, 0]), 2);
    assert_eq!(midpoint(&[-10, 3, 7, 8, -6, -13, 21]), 4);
    assert_eq!(
        midpoint(&[
            1, 1, 1, 1, -5, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
            1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
        ]),
        52
    );
}

fn midpoint(a: &[isize]) -> isize {
    let n = a.len();
    if n < 3 {
        return -1;
    }

    let (mut l, mut r) = (a[0], a[2]);
    for i in 3..n {
        r += a[i];
    }
    for i in 1..n - 1 {
        if l == r {
            return i as isize;
        }
        l += a[i];
        r -= a[i + 1];
    }

    return -1;
}

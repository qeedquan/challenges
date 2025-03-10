/*

Given an array of integers.

Return an array, where the first element is the count of positives numbers and the second element is sum of negative numbers. 0 is neither positive nor negative.

If the input array is empty or null, return an empty array.

Example
For input [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, -11, -12, -13, -14, -15], you should return [10, -65].

*/

fn main() {
    assert_eq!(
        count(&[1, 2, 3, 4, 5, 6, 7, 8, 9, 10, -11, -12, -13, -14, -15]),
        (10, -65)
    );
}

fn count(a: &[isize]) -> (isize, isize) {
    let (mut p, mut n) = (0, 0);
    for &x in a {
        if x < 0 {
            n += x;
        } else if x > 0 {
            p += 1;
        }
    }
    (p, n)
}

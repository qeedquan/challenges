/*

You are given an array (which will have a length of at least 3, but could be very large) containing integers. The array is either entirely comprised of odd integers or entirely comprised of even integers except for a single integer N. Write a method that takes the array as an argument and returns this "outlier" N.

Examples
[2, 4, 0, 100, 4, 11, 2602, 36]
Should return: 11 (the only odd number)

[160, 3, 1719, 19, 11, 13, -21]
Should return: 160 (the only even number)

*/

fn main() {
    assert_eq!(outlier(&vec![2, 4, 0, 100, 4, 11, 2602, 36]), 11);
    assert_eq!(outlier(&vec![160, 3, 1719, 19, 11, 13, -21]), 160);
}

fn outlier(a: &Vec<isize>) -> isize {
    let (mut p0, mut p1) = (0, 0);
    let (mut i0, mut i1) = (0, 0);
    let mut i = 0;
    while i < a.len() {
        if a[i] & 1 == 0 {
            (i0, p0) = (i, p0 + 1);
        } else {
            (i1, p1) = (i, p1 + 1);
        }
        i += 1;
    }

    if p0 < p1 {
        a[i0]
    } else if p0 > p1 {
        a[i1]
    } else {
        -1
    }
}

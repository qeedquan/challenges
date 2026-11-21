use std::cmp::*;

fn main() {
    assert_eq!(parking(&[24, 13, 89, 37]), 152);
    assert_eq!(parking(&[7, 30, 41, 14, 39, 42]), 70);
}

fn parking(a: &[isize]) -> isize {
    let (mut l, mut r) = (isize::MAX, isize::MIN);
    for &x in a {
        l = min(l, x);
        r = max(r, x);
    }
    2 * (r - l)
}

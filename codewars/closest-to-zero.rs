/*

Simply find the closest value to zero from the list. Notice that there are negatives in the list.

List is always not empty and contains only integers. Return None if it is not possible to define only one of such values. And of course, we are expecting 0 as closest value to zero.

Examples:

[2, 4, -1, -3]  => -1
[5, 2, -2]      => None
[5, 2, 2]       => 2
[13, 0, -6]     => 0

*/

fn main() {
    assert_eq!(closest(&[2, 4, -1, -3]), Some(-1));
    assert_eq!(closest(&[5, 2, -2]), None);
    assert_eq!(closest(&[5, 2, 2]), Some(2));
    assert_eq!(closest(&[13, 0, -6]), Some(0));
}

fn closest(a: &[isize]) -> Option<isize> {
    let n = a.len();
    if n == 0 {
        return None;
    }

    let mut r = a[0];
    let mut x = r.abs();
    for i in 1..n {
        let y = a[i].abs();
        if x == y && r != a[i] {
            return None;
        }

        if y < x {
            r = a[i];
            x = y;
        }
    }
    return Some(r);
}

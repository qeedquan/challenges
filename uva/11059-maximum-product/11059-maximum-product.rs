use std::cmp::max;

fn main() {
    assert_eq!(max_product(&[2, 4, -3]), 8);
    assert_eq!(max_product(&[2, 5, -1, 2, -1]), 20);
}

fn max_product(a: &[isize]) -> isize {
    let mut n = 0;
    let mut p = 1;
    let mut r = 0;
    for &v in a {
        p *= v;
        if p == 0 {
            n = 0;
            p = 1;
        } else if p > 0 {
            r = max(r, p);
        } else {
            if n != 0 {
                r = max(r, p / n);
            } else {
                n = p;
            }
            n = max(n, p);
        }
    }
    r
}

fn main() {
    assert_eq!(farey(5, 5), (1, 2));
    assert_eq!(farey(5, 1), (1, 5));
    assert_eq!(farey(5, 9), (4, 5));
    assert_eq!(farey(5, 10), (1, 1));
    assert_eq!(farey(117, 348), (9, 109));
    assert_eq!(farey(288, 10000), (78, 197));
}

fn farey(n: isize, mut k: isize) -> (isize, isize) {
    let mut pa = 0;
    let mut pb = 1;
    let mut a = 1;
    let mut b = n;
    while k - 1 > 0 {
        let tk = (n + pb) / b;
        let ta = (tk * a) - pa;
        let tb = (tk * b) - pb;
        pa = a;
        pb = b;
        a = ta;
        b = tb;
        k -= 1;
    }
    (a, b)
}

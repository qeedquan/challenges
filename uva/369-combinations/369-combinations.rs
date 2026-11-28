fn main() {
    assert_eq!(combinations(100, 6), 1192052400);
    assert_eq!(combinations(20, 5), 15504);
    assert_eq!(combinations(18, 6), 18564);
    assert_eq!(combinations(20, 21), 0);
    assert_eq!(combinations(20, 20), 1);
}

fn combinations(mut n: isize, mut m: isize) -> isize {
    if m > n {
        return 0;
    }

    if n - m < m {
        m = n - m;
    }

    let mut r = 1;
    for i in 1..m + 1 {
        r = (r * n) / i;
        n = n - 1;
    }
    return r;
}

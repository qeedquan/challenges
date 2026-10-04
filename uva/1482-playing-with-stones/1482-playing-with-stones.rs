fn main() {
    assert_eq!(solve(&[4, 4]), "NO");
    assert_eq!(solve(&[1, 2, 3]), "YES");
    assert_eq!(solve(&[2, 4, 6]), "NO");
    assert_eq!(solve(&[1, 2, 1]), "YES");
}

fn solve(a: &[isize]) -> &'static str {
    let mut r = 0;
    for &x in a {
        r ^= sg(x);
    }
    if r != 0 {
        return "YES";
    }
    return "NO";
}

// https://oeis.org/A025480
fn sg(mut n: isize) -> isize {
    if n <= 0 {
        return 0;
    }
    while n & 1 != 0 {
        n /= 2;
    }
    return n / 2;
}

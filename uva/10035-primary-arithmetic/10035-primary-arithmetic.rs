use std::cmp::*;

fn main() {
    assert_eq!(solve("123", "456"), "No carry operation.");
    assert_eq!(solve("555", "555"), "3 carry operations.");
    assert_eq!(solve("123", "594"), "1 carry operation.");
    assert_eq!(solve("99", "1"), "2 carry operations.");
}

fn solve(a: &'static str, b: &'static str) -> String {
    let a = a.as_bytes();
    let b = b.as_bytes();
    let n = a.len();
    let m = b.len();
    let mut c = vec![0; max(n, m) + 2];
    for i in 0..n {
        c[i] += a[n - i - 1] as isize - '0' as isize;
    }
    for i in 0..m {
        c[i] += b[m - i - 1] as isize - '0' as isize;
    }

    let mut r = 0;
    for i in 0..c.len() {
        if c[i] >= 10 && i + 1 < c.len() {
            c[i + 1] += c[i] / 10;
            c[i] %= 10;
            r += 1;
        }
    }

    if r == 0 {
        return format!("No carry operation.");
    }

    let mut p = "";
    if r > 1 {
        p = "s";
    }
    return format!("{} carry operation{}.", r, p);
}

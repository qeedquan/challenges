fn main() {
    assert_eq!(count(1, 4), 2);
    assert_eq!(count(1, 10), 3);
}

fn count(a: isize, b: isize) -> isize {
    let mut c = 0;
    for i in a..b + 1 {
        let s = (i as f64).sqrt() as isize;
        if i == s * s {
            c += 1;
        }
    }
    c
}

fn main() {
    assert_eq!(solve(1, 6), 3);
    assert_eq!(solve(3, 10), 5);
    assert_eq!(solve(3, 14), 6);
}

fn solve(s: i128, d: i128) -> i128 {
    let mut i = s;
    let mut s = 0;
    loop {
        s += i;
        if s >= d {
            break;
        }
        i += 1;
    }
    return i;
}

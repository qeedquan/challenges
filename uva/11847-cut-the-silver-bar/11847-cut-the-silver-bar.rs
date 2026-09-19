fn main() {
    assert_eq!(solve(1), 0);
    assert_eq!(solve(5), 2);
    assert_eq!(solve(3), 1);
}

fn solve(n: isize) -> isize {
    if n < 1 {
        return 0;
    }
    (n as f64).log2() as isize
}

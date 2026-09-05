fn main() {
    assert_eq!(solve(1), 1);
    assert_eq!(solve(2), 2);
    assert_eq!(solve(3), 4);
    assert_eq!(solve(4), 8);
}

fn solve(n: i128) -> i128 {
    (n * (n - 1) * (n - 2) * (n - 3) / 24) + (n * (n - 1) / 2) + 1
}

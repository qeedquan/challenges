fn main() {
    assert_eq!(solve(0, 0), 1);
    assert_eq!(solve(1, 2), 8);
    assert_eq!(solve(2, 0), 6);
}

#[allow(non_snake_case)]
fn solve(N: i128, M: i128) -> i128 {
    let S = N + M;
    (S * (S + 1) / 2) + N + 1
}

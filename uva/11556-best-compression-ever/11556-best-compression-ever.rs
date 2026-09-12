fn main() {
    assert_eq!(solve(13, 3), "yes");
    assert_eq!(solve(1, 0), "yes");
    assert_eq!(solve(31415926535897, 40), "no");
}

fn solve(a: u128, b: u128) -> &'static str {
    if a < (1 << (b + 1)) {
        "yes"
    } else {
        "no"
    }
}

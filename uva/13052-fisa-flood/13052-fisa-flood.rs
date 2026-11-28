fn main() {
    assert_eq!(solve(1, 0), (1, 0));
    assert_eq!(solve(0, 2), (1, 0));
    assert_eq!(solve(1, 1), (0, 1));
}

#[allow(non_snake_case)]
fn solve(A: isize, B: isize) -> (isize, isize) {
    if A == 0 && B == 0 {
        return (0, 0);
    }
    if B % 2 == 0 {
        return (1, 0);
    }
    return (0, 1);
}

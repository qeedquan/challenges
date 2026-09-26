fn main() {
    assert_eq!(solve(90), 'Y');
    assert_eq!(solve(65), 'N');
    assert_eq!(solve(66), 'Y');
    assert_eq!(solve(67), 'N');
    assert_eq!(solve(128), 'N');
    assert_eq!(solve(0), 'Y');
    assert_eq!(solve(180), 'Y');
}

fn solve(a: isize) -> char {
    if a % 6 == 0 {
        'Y'
    } else {
        'N'
    }
}

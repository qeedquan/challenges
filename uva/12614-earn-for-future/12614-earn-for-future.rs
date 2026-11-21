fn main() {
    assert_eq!(solve(&[0, 1]), 1);
    assert_eq!(solve(&[]), 0);
    assert_eq!(solve(&[0, 1, 5, 6]), 6);
}

fn solve(cards: &[isize]) -> isize {
    if let Some(value) = cards.iter().max() {
        return *value;
    }
    return 0;
}

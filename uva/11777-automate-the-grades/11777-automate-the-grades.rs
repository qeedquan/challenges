fn main() {
    assert_eq!(solve(15, 18, 25, 8, 15, 17, 12), 'B');
    assert_eq!(solve(20, 20, 30, 10, 20, 20, 20), 'A');
    assert_eq!(solve(20, 20, 30, 10, 18, 0, 0), 'B');
}

fn solve(
    term1: isize,
    term2: isize,
    r#final: isize,
    attendance: isize,
    test1: isize,
    test2: isize,
    test3: isize,
) -> char {
    let mut tests = [test1, test2, test3];
    tests.sort();

    let total = term1 + term2 + r#final + attendance + (tests[1] + tests[2]) / 2;
    if total >= 90 {
        'A'
    } else if total >= 80 {
        'B'
    } else if total >= 70 {
        'C'
    } else if total >= 60 {
        'D'
    } else {
        'F'
    }
}

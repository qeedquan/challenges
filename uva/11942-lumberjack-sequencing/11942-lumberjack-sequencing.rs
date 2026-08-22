fn main() {
    assert_eq!(solve(&[13, 25, 39, 40, 55, 62, 68, 77, 88, 95]), "Ordered");
    assert_eq!(
        solve(&[88, 62, 77, 20, 40, 10, 99, 56, 45, 36]),
        "Unordered"
    );
    assert_eq!(solve(&[91, 78, 61, 59, 54, 49, 43, 33, 26, 18]), "Ordered");
}

fn solve(lumberjacks: &[isize]) -> &'static str {
    let mut direction = 0;
    for i in 1..lumberjacks.len() {
        if lumberjacks[i] < lumberjacks[i - 1] {
            direction |= 0x1;
        } else if lumberjacks[i] > lumberjacks[i - 1] {
            direction |= 0x2;
        }
    }
    if direction == 0x3 {
        return "Unordered";
    }
    return "Ordered";
}

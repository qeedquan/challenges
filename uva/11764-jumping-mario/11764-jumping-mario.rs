fn main() {
    assert_eq!(solve(&[1, 4, 2, 2, 3, 5, 3, 4]), (4, 2));
    assert_eq!(solve(&[9]), (0, 0));
    assert_eq!(solve(&[1, 2, 3, 4, 5]), (4, 0));
}

fn solve(walls: &[isize]) -> (isize, isize) {
    if walls.len() == 0 {
        return (0, 0);
    }

    let (mut high, mut low, mut last) = (0, 0, walls[0]);
    for &wall in &walls[1..] {
        if wall > last {
            high += 1;
        }
        if wall < last {
            low += 1;
        }
        last = wall;
    }
    return (high, low);
}

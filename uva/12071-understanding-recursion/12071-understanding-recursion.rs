fn main() {
    assert_eq!(solve(&mut [1, 2, 3, 4]), 6);
    assert_eq!(solve(&mut [6, 1]), 1);
}

fn solve(a: &mut [isize]) -> usize {
    a.sort();

    let (mut j, mut r) = (0, 0);
    for i in 1..a.len() {
        while a[j] < a[i] {
            j += 1;
        }
        r += j;
    }
    r
}

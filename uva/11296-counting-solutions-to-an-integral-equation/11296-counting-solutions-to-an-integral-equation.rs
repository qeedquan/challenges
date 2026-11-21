fn main() {
    assert_eq!(solve(2), 3);
    assert_eq!(solve(3), 3);

    for i in 0..100 {
        assert_eq!(solve(i), solvebf(i));
    }
}

fn solve(mut n: i128) -> i128 {
    n = (n + (2 - (n % 2))) / 2;
    n * (n + 1) / 2
}

fn solvebf(n: i128) -> i128 {
    let mut c = 0;
    for x in 0..=n {
        for y in 0..=n {
            for z in 0..=n {
                if x + (2 * y) + (2 * z) == n {
                    c += 1;
                }
            }
        }
    }
    c
}

fn main() {
    assert_eq!(solve(195), (4, 9339));
    assert_eq!(solve(265), (5, 45254));
    assert_eq!(solve(750), (3, 6666));
}

fn solve(mut n: i128) -> (i128, i128) {
    let mut c = 0;
    loop {
        let (a, mut b) = (n, 0);
        while n != 0 {
            b = (b * 10) + (n % 10);
            n /= 10;
        }
        if a == b {
            return (c, a);
        }
        c = c + 1;
        n = a + b;
    }
}

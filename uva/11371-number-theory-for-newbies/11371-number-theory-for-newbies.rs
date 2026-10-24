fn main() {
    assert_eq!(solve(123), "321 - 123 = 198 = 9 * 22");
    assert_eq!(solve(2468), "8642 - 2468 = 6174 = 9 * 686");
}

fn solve(n: usize) -> String {
    let n2 = shufmax(n);
    let n3 = n2 - n;
    format!("{} - {} = {} = 9 * {}", n2, n, n3, n3 / 9)
}

fn shufmax(mut n: usize) -> usize {
    let mut d = [0; 10];
    while n > 0 {
        d[n % 10] += 1;
        n /= 10;
    }

    let mut r = 0;
    for i in (0..10).rev() {
        for _ in 0..d[i] {
            r = (r * 10) + i;
        }
    }
    r
}

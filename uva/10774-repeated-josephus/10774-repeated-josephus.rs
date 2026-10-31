fn main() {
    assert_eq!(solve(13), (2, 7));
    assert_eq!(solve(23403), (8, 1023));
}

fn solve(mut n: isize) -> (isize, isize) {
    for i in 0..isize::MAX {
        let s = josephus(n, 2);
        if s == n {
            return (i, s);
        }
        n = s;
    }
    return (-1, -1);
}

fn josephus(n: isize, k: isize) -> isize {
    let mut r = 0;
    for i in 2..=n {
        r = (r + k) % i;
    }
    r + 1
}

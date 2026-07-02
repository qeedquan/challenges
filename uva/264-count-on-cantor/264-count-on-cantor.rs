fn main() {
    assert_eq!(cantor(3), (2, 1));
    assert_eq!(cantor(14), (2, 4));
    assert_eq!(cantor(7), (1, 4));
}

fn cantor(n: isize) -> (isize, isize) {
    if n < 1 {
        return (0, 0);
    }

    let x = ((((8 * (n - 1) + 1) as f64).sqrt() - 1.0) / 2.0) as isize;
    let y = (1 + x) * x / 2;
    let y = n - y;
    if x % 2 != 0 {
        return (y, x + 2 - y);
    }
    return (x + 2 - y, y);
}

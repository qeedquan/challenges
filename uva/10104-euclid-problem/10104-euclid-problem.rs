fn main() {
    assert_eq!(exgcd(4, 6), (-1, 1, 2));
    assert_eq!(exgcd(17, 17), (0, 1, 17));
}

fn exgcd(a: isize, b: isize) -> (isize, isize, isize) {
    if b == 0 {
        return (1, 0, a);
    }

    let (x, y, d) = exgcd(b, a % b);
    return (y, x - (a / b) * y, d);
}

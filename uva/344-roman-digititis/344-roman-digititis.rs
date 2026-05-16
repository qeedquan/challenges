#![allow(non_snake_case)]

fn main() {
    assert_eq!(roman(1), (1, 0, 0, 0, 0));
    assert_eq!(roman(2), (3, 0, 0, 0, 0));
    assert_eq!(roman(20), (28, 10, 14, 0, 0));
    assert_eq!(roman(99), (140, 50, 150, 50, 10));
}

fn roman(n: usize) -> (usize, usize, usize, usize, usize) {
    let (mut i, mut v, mut x, mut l, mut c) = (0, 0, 0, 0, 0);
    for a in 1..=n {
        i += I(a);
        v += V(a);
        x += X(a);
        l += L(a);
        c += C(a);
    }
    (i, v, x, l, c)
}

fn I(mut n: usize) -> usize {
    n %= 5;
    if n == 4 {
        return 1;
    }
    return n;
}

fn V(mut n: usize) -> usize {
    n %= 10;
    if n >= 4 && n <= 8 {
        return 1;
    }
    return 0;
}

fn X(mut n: usize) -> usize {
    n %= 50;
    if n <= 8 {
        return 0;
    } else if n >= 9 && n <= 18 {
        return 1;
    } else if n >= 19 && n <= 28 {
        return 2;
    } else if n >= 29 && n <= 38 {
        return 3;
    } else if n == 39 {
        return 4;
    } else if n >= 40 && n <= 48 {
        return 1;
    }
    return 2;
}

fn L(n: usize) -> usize {
    if n >= 40 && n <= 89 {
        return 1;
    }
    return 0;
}

fn C(n: usize) -> usize {
    if n >= 90 {
        return 1;
    }
    return 0;
}

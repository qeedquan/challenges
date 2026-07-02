fn main() {
    assert_eq!(solve(3), 1);
    assert_eq!(solve(10), 5);
    assert_eq!(solve(81), 40);
    for i in 0..1000000 {
        assert_eq!(solve(i), solvebf(i));
    }
}

fn solve(n: isize) -> isize {
    if n < 1 {
        return 0;
    }
    return n / 2;
}

fn solvebf(mut n: isize) -> isize {
    if n < 1 {
        return 0;
    }

    let mut c = 0;
    loop {
        let m = n / 3;
        if m == 0 {
            break;
        }
        n = (n % 3) + m;
        c += m;
    }
    if n % 3 == 2 {
        c += 1;
    }

    return c;
}

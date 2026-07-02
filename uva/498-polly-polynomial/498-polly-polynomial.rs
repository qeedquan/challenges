fn main() {
    assert_eq!(solve(&[-2], &[5, 0, 1, 6]), &[-2, -2, -2, -2]);
    assert_eq!(solve(&[1, -1], &[7, 6, -1]), &[6, 5, -2]);
}

fn solve(c: &[isize], x: &[isize]) -> Vec<isize> {
    let mut r = vec![];
    for &x in x {
        r.push(eval(c, x));
    }
    r
}

fn eval(c: &[isize], x: isize) -> isize {
    let mut r = 0;
    let mut p = 1;
    for i in (0..c.len()).rev() {
        r += c[i] * p;
        p *= x;
    }
    r
}

/*

Some numbers can be represented as perfect powers of other numbers. A number x can be represented as x = base^power for some integer base and power.

Given an integer x you have to find the largest value of power, such that base is also an integer.

Sample Input:
9
Sample Output:
2

*/

fn main() {
    assert_eq!(largestpower(1), 1);
    assert_eq!(largestpower(2), 1);
    assert_eq!(largestpower(4), 2);
    assert_eq!(largestpower(9), 2);
    assert_eq!(largestpower(42), 1);
    assert_eq!(largestpower(1024), 10);
}

fn largestpower(n: isize) -> isize {
    let mut r = -1;
    for p in 0..n + 1 {
        for b in 0..n + 1 {
            let (x, v) = ipow(b, p);
            if !v || x > n {
                break;
            }
            if x == n {
                r = p;
            }
        }
    }
    return r;
}

fn ipow(x: isize, p: isize) -> (isize, bool) {
    let mut r: isize = 1;
    for _ in 0..p {
        if r.checked_mul(x).is_none() {
            return (r, false);
        }
        r *= x;
    }
    return (r, true);
}

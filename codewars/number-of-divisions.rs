/*

Calculate how many times a number can be divided by a given number.

Example
For example the number 6 can be divided by 2 two times:

1. 6 / 2 = 3
2. 3 / 2 = 1 remainder = 1

100 can be divided by 2 six times:

1. 100 / 2 = 50
2. 50 / 2 = 25
3. 25 / 2 = 12 remainder 1
4. 12 / 2 = 6
5. 6 / 2 = 3
6. 3 / 2 = 1 remainder 1

*/

fn main() {
    assert_eq!(divisions(6, 2), 2);
    assert_eq!(divisions(100, 2), 6);
    assert_eq!(divisions(9999, 3), 8);
    assert_eq!(divisions(2450, 5), 4);
    assert_eq!(divisions(2, 3), 0);
    assert_eq!(divisions(5, 5), 1);
}

fn divisions(mut x: usize, d: usize) -> isize {
    if d < 2 {
        return -1;
    }

    let mut c = 0;
    while x >= d {
        x /= d;
        c += 1;
    }
    c
}

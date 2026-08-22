/*

I have a number like this:

n = 548915381
The output should be the sum of every second number. In this case 26:

4+9+5+8 = 26
Rules:

This is a code-golf, so the shortest code in bytes wins.
The input consists only of numbers bigger than 10 (at least 2 digits) but smaller than an int32.
The input will be a number, not a string
Test cases:

Input	Output
10           0
101011       1
548915381   26
999999      27
2147483647  29
999999999   36

*/

fn main() {
    assert_eq!(digitsum2(10), 0);
    assert_eq!(digitsum2(101011), 1);
    assert_eq!(digitsum2(548915381), 26);
    assert_eq!(digitsum2(999999), 27);
    assert_eq!(digitsum2(2147483647), 29);
    assert_eq!(digitsum2(999999999), 36);
}

fn digitsum2(n: usize) -> usize {
    let d = digits(n);
    let mut i = d.len();
    let mut r = 0;
    while i > 1 {
        r += d[i - 2];
        i -= 2;
    }
    r
}

fn digits(mut n: usize) -> Vec<usize> {
    let mut d = vec![];
    while n > 0 {
        d.push(n % 10);
        n /= 10;
    }
    d
}

/*

Originally the Multiplicative digital root

Challenge
Basically do what the title says

Method
Given a positive integer 1 <= N <= 100000000 through one of our standard input methods, multiply every digit together, ignoring zeroes.

Ex: Take a number, say 361218402:

3 * 6 = 18
18 * 1 = 18
18 * 2 = 36
36 * 1 = 36
36 * 8 = 288
288 * 4 = 1152
1152 * 1 (ignore zeroes or turn them into ones) = 1152
1152 * 2 = 2304
The output for 361218402 is 2304

Note: Treat the digit 0 in numbers as 1.

Test Cases
1 => 1
10 => 1
20 => 2
100 => 1
999 => 729
21333 => 54
17801 => 56
4969279 => 244944
100000000 => 1

Standard Loopholes are disallowed, and this is code-golf, so shortest byte count wins!

*/

use std::cmp::*;

fn main() {
    assert_eq!(nzdp(361218402), 2304);
    assert_eq!(nzdp(1), 1);
    assert_eq!(nzdp(10), 1);
    assert_eq!(nzdp(20), 2);
    assert_eq!(nzdp(100), 1);
    assert_eq!(nzdp(999), 729);
    assert_eq!(nzdp(21333), 54);
    assert_eq!(nzdp(17801), 56);
    assert_eq!(nzdp(4969279), 244944);
    assert_eq!(nzdp(100000000), 1);
}

fn nzdp(n: usize) -> usize {
    let d = digits(n);
    let l = d.len();

    let mut r = d[l - 1];
    let mut i = l - 1;
    if l >= 2 {
        r *= d[l - 2];
        i -= 1;
    }

    while i > 0 {
        r *= d[i - 1];
        i -= 1;
    }
    r
}

fn digits(mut n: usize) -> Vec<usize> {
    let mut r = vec![];
    loop {
        r.push(max(1, n % 10));

        n /= 10;
        if n == 0 {
            break;
        }
    }
    r
}

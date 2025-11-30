/*

You're given two integers – n and k. n is always positive, while k >= 0. Write a function that returns first k odd digits in a number n.

The output should also be an integer.

In the following cases a function should return 0:

there are no odd digits in a number n;
k is bigger than a number of digits in n;
k = 0;
k is bigger than a number of odd digits in n.
BTW, is 0 an odd number or an even one?

*/

fn main() {
    assert_eq!(find_odd_digits(123456789111, 5), 13579);
    assert_eq!(find_odd_digits(7459274655920285, 8), 75975595);
    assert_eq!(find_odd_digits(0, 100), 0);
    assert_eq!(find_odd_digits(103756254800023, 2), 13);
    assert_eq!(find_odd_digits(20406886, 6), 0);
    assert_eq!(find_odd_digits(11111333333307, 13), 1111133333337);
    assert_eq!(find_odd_digits(30982, 3), 0);
}

fn find_odd_digits(n: u64, k: u64) -> u64 {
    let (mut r, mut i, s) = (0, 0, format!("{n}"));
    for c in s.chars() {
        if i >= k {
            break;
        }

        match c {
            '1' | '3' | '5' | '7' | '9' => {
                r = (r * 10) + (c as u64 - '0' as u64);
                i += 1;
            }
            _ => (),
        }
    }
    if k > i {
        r = 0;
    }
    r
}

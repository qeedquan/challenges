/*

###Lucky number

Write a function to find if a number is lucky or not. If the sum of all digits is 0 or multiple of 9 then the number is lucky.

1892376 => 1+8+9+2+3+7+6 = 36. 36 is divisible by 9, hence number is lucky.

Function will return true for lucky numbers and false for others.

*/

fn main() {
    assert_eq!(lucky(1892376), true);

    for i in 0..100000000 {
        assert_eq!(lucky(i), luckybf(i));
    }
}

// https://oeis.org/A008591
fn lucky(n: usize) -> bool {
    n % 9 == 0
}

fn luckybf(n: usize) -> bool {
    digsum(n) % 9 == 0
}

fn digsum(mut n: usize) -> usize {
    let mut r = 0;
    while n > 0 {
        r += n % 10;
        n /= 10;
    }
    r
}

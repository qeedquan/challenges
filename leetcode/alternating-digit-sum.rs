/*

You are given a positive integer n. Each digit of n has a sign according to the following rules:

The most significant digit is assigned a positive sign.
Each other digit has an opposite sign to its adjacent digits.
Return the sum of all digits with their corresponding sign.

Example 1:

Input: n = 521
Output: 4
Explanation: (+5) + (-2) + (+1) = 4.

Example 2:

Input: n = 111
Output: 1
Explanation: (+1) + (-1) + (+1) = 1.

Example 3:

Input: n = 886996
Output: 0
Explanation: (+8) + (-8) + (+6) + (-9) + (+9) + (-6) = 0.

Constraints:

1 <= n <= 10^9

Hint 1
The first step is to loop over the digits. We can convert the integer into a string, an array of digits, or just loop over its digits.

Hint 2
Keep a variable sign that initially equals 1 and a variable answer that initially equals 0.

Hint 3
Each time you loop over a digit i, add sign * i to answer, then multiply sign by -1.

*/

fn main() {
    let tab = vec![
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 0, -1, -2, -3, -4, -5, -6, -7, -8, 2, 1, 0, -1, -2, -3,
        -4, -5, -6, -7, 3, 2, 1, 0, -1, -2, -3, -4, -5, -6, 4, 3, 2, 1, 0, -1, -2, -3, -4, -5, 5,
        4, 3, 2, 1, 0, -1, -2, -3, -4, 6, 5, 4, 3, 2, 1, 0, -1, -2, -3, 7, 6, 5, 4, 3, 2, 1, 0, -1,
        -2, 8, 7, 6, 5, 4, 3, 2,
    ];

    for i in 0..tab.len() {
        assert_eq!(altdigsum(i as isize), tab[i]);
    }

    assert_eq!(altdigsum(521), 4);
    assert_eq!(altdigsum(111), 1);
    assert_eq!(altdigsum(886996), 0);
}

// https://oeis.org/A225693
fn altdigsum(mut n: isize) -> isize {
    let mut r = 0;
    let mut s = 1;
    while n > 0 {
        s = -s;
        r += s * (n % 10);
        n /= 10;
    }
    r * s
}

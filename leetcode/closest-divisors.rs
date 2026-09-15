/*

Given an integer num, find the closest two integers in absolute difference whose product equals num + 1 or num + 2.

Return the two integers in any order.

Example 1:

Input: num = 8
Output: [3,3]
Explanation: For num + 1 = 9, the closest divisors are 3 & 3, for num + 2 = 10, the closest divisors are 2 & 5, hence 3 & 3 is chosen.
Example 2:

Input: num = 123
Output: [5,25]
Example 3:

Input: num = 999
Output: [40,25]


Constraints:

1 <= num <= 10^9

*/

fn main() {
    assert_eq!(closest_divisors(8), (3, 3));
    assert_eq!(closest_divisors(123), (5, 25));
    assert_eq!(closest_divisors(999), (25, 40));
}

// https://helloacm.com/finding-the-closest-divisors/
fn closest_divisors(n: isize) -> (isize, isize) {
    let mut m = ((n + 2) as f64).sqrt() as isize;
    while m > 0 {
        if (n + 1) % m == 0 {
            return (m, (n + 1) / m);
        }
        if (n + 2) % m == 0 {
            return (m, (n + 2) / m);
        }
        m -= 1;
    }
    return (-1, -1);
}

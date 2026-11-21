/*

Given a non-negative integer c, decide whether there're two integers a and b such that a^2 + b^2 = c.

Example 1:

Input: c = 5
Output: true
Explanation: 1 * 1 + 2 * 2 = 5
Example 2:

Input: c = 3
Output: false
 

Constraints:

0 <= c <= 2^31 - 1

*/

fn main() {
    assert_eq!(judgesquaresum(5), true);
    assert_eq!(judgesquaresum(3), false);
    assert_eq!(judgesquaresum(13), true);
    assert_eq!(judgesquaresum(153), true);
    assert_eq!(judgesquaresum(676), true);
}

// https://oeis.org/A001481
fn judgesquaresum(c: usize) -> bool {
    let mut a = 0;
    let mut b = (c as f64).sqrt() as usize;
    while a <= b {
        let s = (a * a) + (b * b);
        if s == c {
            return true;
        }
        if s < c {
            a += 1;
        } else {
            b -= 1;
        }
    }
    return false;
}

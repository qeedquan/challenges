/*

Given an integer n (in base 10) and a base k, return the sum of the digits of n after converting n from base 10 to base k.

After converting, each digit should be interpreted as a base 10 number, and the sum should be returned in base 10.

Example 1:

Input: n = 34, k = 6
Output: 9
Explanation: 34 (base 10) expressed in base 6 is 54. 5 + 4 = 9.

Example 2:

Input: n = 10, k = 10
Output: 1
Explanation: n is already in base 10. 1 + 0 = 1.

Constraints:

    1 <= n <= 100
    2 <= k <= 10

*/

fn main() {
    assert_eq!(sumbase(34, 6), 9);
    assert_eq!(sumbase(10, 10), 1);
}

fn sumbase(n: usize, k: usize) -> usize {
    digitsum(convb(n, k, 10))
}

fn digitsum(mut n: usize) -> usize {
    let mut r = 0;
    while n > 0 {
        r += n % 10;
        n /= 10;
    }
    r
}

fn convb(mut n: usize, b: usize, p: usize) -> usize {
    if b == 0 {
        return 0;
    }

    let mut d = vec![];
    while n > 0 {
        d.push(n % b);
        n /= b;
    }

    let mut r = 0;
    let mut l = d.len();
    while l > 0 {
        r = (r * p) + d[l - 1];
        l -= 1;
    }
    r
}

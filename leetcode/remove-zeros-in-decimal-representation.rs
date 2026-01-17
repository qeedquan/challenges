/*

You are given a positive integer n.

Return the integer obtained by removing all zeros from the decimal representation of n.

Example 1:

Input: n = 1020030

Output: 123

Explanation:

After removing all zeros from 1020030, we get 123.

Example 2:

Input: n = 1

Output: 1

Explanation:

1 has no zero in its decimal representation. Therefore, the answer is 1.

Constraints:

1 <= n <= 10^15

Hint 1
Convert to a string and filter out the '0' characters.

*/

fn main() {
    let tab = vec![
        1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 11, 12, 13, 14, 15, 16, 17, 18, 19, 2, 21, 22, 23, 24, 25,
        26, 27, 28, 29, 3, 31, 32, 33, 34, 35, 36, 37, 38, 39, 4, 41, 42, 43, 44, 45, 46, 47, 48,
        49, 5, 51, 52, 53, 54, 55, 56, 57, 58, 59, 6, 61, 62, 63, 64, 65, 66, 67, 68, 69, 7, 71,
        72, 73, 74, 75, 76, 77, 78, 79, 8, 81, 82, 83, 84, 85, 86, 87, 88, 89, 9, 91, 92, 93, 94,
        95, 96, 97, 98, 99, 1, 11, 12, 13, 14, 15, 16, 17, 18, 19, 11, 111, 112, 113, 114, 115,
        116, 117, 118, 119, 12,
    ];

    assert_eq!(rmz(1020030), 123);
    assert_eq!(rmz(1), 1);
    for i in 0..tab.len() {
        assert_eq!(rmz(i + 1), tab[i]);
    }
}

// https://oeis.org/A004719
fn rmz(mut n: usize) -> usize {
    let (mut r, mut p) = (0, 1);
    while n > 0 {
        let d = n % 10;
        if d > 0 {
            r += d * p;
            p *= 10;
        }
        n /= 10;
    }
    r
}

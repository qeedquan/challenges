/*

Your task is to make a function that can take any non-negative integer as an argument and return it with its digits in descending order.
Essentially, rearrange the digits to create the highest possible number.

Examples:
Input: 42145 Output: 54421

Input: 145263 Output: 654321

Input: 123456789 Output: 987654321

*/

fn main() {
    assert_eq!(sortdesc(42145), 54421);
    assert_eq!(sortdesc(145263), 654321);
    assert_eq!(sortdesc(123456789), 987654321);
}

fn sortdesc(mut n: usize) -> usize {
    let mut d = [0; 10];
    while n > 0 {
        d[n % 10] += 1;
        n /= 10;
    }

    let mut r = 0;
    for i in (0..10).rev() {
        for _ in 0..d[i] {
            r = (r * 10) + i;
        }
    }
    r
}

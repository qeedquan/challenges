/*

Given a number return the closest number to it that is divisible by 10.

Example input:

22
25
37
Expected output:

20
30
40

*/

fn main() {
    assert_eq!(round10(22), 20);
    assert_eq!(round10(25), 30);
    assert_eq!(round10(37), 40);
    assert_eq!(round10(2), 0);
}

fn round10(x: usize) -> usize {
    let m = x % 10;
    if m < 5 {
        return x - m;
    }
    return x + 10 - m;
}

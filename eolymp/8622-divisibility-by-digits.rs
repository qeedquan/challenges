/*

Four-digit natural number is given. Determine whether it is divisible by each of its digits.

Input
One four-digit natural number.

Output
Print "YES" if the number is divisible by each of its digits, and "NO" otherwise.

Examples

Input #1
2244

Answer #1
YES

Input #2
2344

Answer #2
NO

*/

fn main() {
    assert_eq!(solve(2244), "YES");
    assert_eq!(solve(2344), "NO");
}

fn solve(n: usize) -> &'static str {
    let mut m = n;
    while m > 0 {
        if n % (m % 10) != 0 {
            return "NO";
        }
        m /= 10;
    }
    return "YES";
}

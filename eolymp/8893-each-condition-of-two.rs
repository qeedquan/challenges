/*

For the given integer n print "YES", if each of the following conditions holds and "NO" otherwise.

number n is divisible by 3;

number n is even and two-digit.

Input
One integer n.

Output
Print "YES" or "NO" depending on conditions.

Examples

Input #1
12

Answer #1
YES

Input #2
27

Answer #2
NO

*/

fn main() {
    assert_eq!(solve(12), "YES");
    assert_eq!(solve(27), "NO");
}

fn solve(n: isize) -> &'static str {
    if (n % 3) == 0 && (n % 2 == 0) && 10 <= n && n <= 99 {
        return "YES";
    }
    return "NO";
}

/*

A five-digit natural number is given. Determine whether the number contains at least two identical digits.

Input
One five-digit number.

Output
Print "YES" if the number has at least two identical digits. Print "NO" otherwise.

Examples

Input #1
12345

Answer #1
NO

Input #2
63456

Answer #2
YES

*/

fn main() {
    assert_eq!(solve(12345), "NO");
    assert_eq!(solve(63456), "YES");
}

fn solve(mut n: usize) -> &'static str {
    let mut d = [0; 10];
    while n > 0 {
        let i = n % 10;
        d[i] += 1;
        if d[i] >= 2 {
            return "YES";
        }
        n /= 10;
    }
    return "NO";
}

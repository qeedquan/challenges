/*

Remove all even digits from the given positive integer.

Input
One positive integer n (n≤10^18).

Output
Print the number n with all even digits removed. If the original number n contains only even digits, print 0.

Examples

Input #1
12345678901234

Answer #1
1357913

Input #2
24642

Answer #2
0

*/

fn main() {
    assert_eq!(solve(12345678901234), 1357913);
    assert_eq!(solve(24642), 0);
}

fn solve(mut n: usize) -> usize {
    let mut r = 0;
    let mut p = 1;
    while n > 0 {
        let d = n % 10;
        if (d & 1) != 0 {
            r += d * p;
            p *= 10;
        }
        n /= 10;
    }
    r
}

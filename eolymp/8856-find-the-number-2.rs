/*

In a three-digit number N, the first digit was removed.
The remaining part was then multiplied by 10, and the original first digit was added to the result, giving the number X.
Find X, given the value of N.

Input
A three-digit natural number N.

Output
The value of X.

Examples
Input #1
123

Answer #1
231

*/

fn main() {
    assert_eq!(solve(123), 231);
}

fn solve(n: usize) -> usize {
    let a = (n / 100) % 10;
    let b = (n % 100) * 10;
    a + b
}

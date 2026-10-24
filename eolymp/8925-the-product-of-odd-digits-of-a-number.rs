/*

Calculate the product of the odd digits in a natural number n.

Input
A natural number n.

Output
Print the product of the odd digits. If there are no odd digits, output -1.

Examples

Input #1
327

Answer #1
21

*/

fn main() {
    assert_eq!(solve(327), 21);
}

fn solve(mut n: isize) -> isize {
    let (mut r, mut f) = (1, 0);
    while n != 0 {
        let d = n % 10;
        if d & 1 != 0 {
            r *= d;
            f = 1;
        }
        n /= 10;
    }
    if f == 0 {
        -1
    } else {
        r
    }
}

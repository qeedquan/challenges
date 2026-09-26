/*

Given a rectangle with sides a and b, determine the area of the smallest square that can completely contain this rectangle.

https://static.e-olymp.com/content/6a/6a6d5a101596fe62c35604bcf132cd42132bf66e.png

Input
Two integers a and b (a,b≤1000) — the sides of the rectangle.

Output
Output a single integer — the area of the smallest square that can contain the rectangle.

Examples

Input #1
2 3

Answer #1
16

Input #8
1000 1000

Answer #8
4000000

*/

fn main() {
    assert_eq!(solve(2, 3), 16);
    assert_eq!(solve(1000, 1000), 4000000);
}

fn solve(mut a: usize, mut b: usize) -> usize {
    if a > b {
        (a, b) = (b, a);
    }

    if 2 * a <= b {
        return b * b;
    }
    return 4 * a * a;
}

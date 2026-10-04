/*

https://static.e-olymp.com/content/3c/3cc1df8493c204a4995944d11d019f868f063cb4.jpg

Even in ancient times, the Egyptians knew that a triangle with sides 3, 4, and 5 is a right triangle, with its right angle being the largest one.
Determine whether other triangles also have this property.

Input
The input consists of several test cases, ending with the line 0 0 0.
Each test case contains three positive integers — the lengths of the sides of a triangle.
All numbers do not exceed 30000.

Output
For each test case, print on a separate line right if the triangle is right-angled, or wrong otherwise.

Examples

Input #1
6 8 10
25 52 60
5 12 13
0 0 0

Answer #1
right
wrong
right

*/

fn main() {
    assert_eq!(solve(6, 8, 10), "right");
    assert_eq!(solve(25, 52, 60), "wrong");
    assert_eq!(solve(5, 12, 13), "right");
}

fn solve(a: isize, b: isize, c: isize) -> &'static str {
    if check(a, b, c) || check(b, a, c) || check(c, a, b) {
        "right"
    } else {
        "wrong"
    }
}

fn check(a: isize, b: isize, c: isize) -> bool {
    (a * a) == (b * b) + (c * c)
}

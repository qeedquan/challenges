/*

One of the famous proofs of modern mathematics is Georg Cantor’s demonstration that the set of
rational numbers is enumerable. The proof works by using an explicit enumeration of rational numbers
as shown in the diagram below.
1/1 1/2 1/3 1/4 1/5 . . .
2/1 2/2 2/3 2/4
3/1 3/2 3/3
4/1 4/2
5/1
In the above diagram, the first term is 1/1, the second term is 1/2, the third term is 2/1, the fourth
term is 3/1, the fifth term is 2/2, and so on.

Input and Output
You are to write a program that will read a list of numbers in the range from 1 to 107 and will print
for each number the corresponding term in Cantor’s enumeration as given below. No blank line should
appear after the last number.
The input list contains a single number per line and will be terminated by end-of-file.

Sample input
3
14
7

Sample output
TERM 3 IS 2/1
TERM 14 IS 2/4
TERM 7 IS 1/4

*/

fn main() {
    assert_eq!(cantor(3), (2, 1));
    assert_eq!(cantor(14), (2, 4));
    assert_eq!(cantor(7), (1, 4));
}

fn cantor(n: isize) -> (isize, isize) {
    if n < 1 {
        return (0, 0);
    }

    let x = ((((8 * (n - 1) + 1) as f64).sqrt() - 1.0) / 2.0) as isize;
    let y = (1 + x) * x / 2;
    let y = n - y;
    if x % 2 != 0 {
        return (y, x + 2 - y);
    }
    return (x + 2 - y, y);
}

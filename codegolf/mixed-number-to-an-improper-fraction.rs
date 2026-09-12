/*

In this challenge you will be converting a mixed number to an improper fraction.

Because improper fractions use fewer numbers, your code will need to be as short as possible.

Examples
4 1/2
9/2

12 2/4
50/4

0 0/2
0/2

11 23/44
507/44

Specification
You may assume the denominator of the input will never be 0. The input will always be in the format x y/z where x,y,z are arbitrary nonnegative integers. You do not need to simplify the output.

This is code-golf so shortest code in bytes wins.

*/

fn main() {
    assert_eq!(mix2frac(4, (1, 2)), (9, 2));
    assert_eq!(mix2frac(12, (2, 4)), (50, 4));
    assert_eq!(mix2frac(0, (0, 2)), (0, 2));
    assert_eq!(mix2frac(11, (23, 44)), (507, 44));
}

fn mix2frac(x: isize, (a, b): (isize, isize)) -> (isize, isize) {
    (x * b + a, b)
}

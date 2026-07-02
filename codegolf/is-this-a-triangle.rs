/*

Task
Write a function/program that, given three positive integers a, b and c, prints a Truthy value if a triangle (any triangle) could have side lengths a, b and c and outputs a Falsy value otherwise.

Input
Three positive integers in any sensible format, for example:

three distinct function arguments, f(2, 3, 5)
a list of three numbers, [2,3,5]
a comma-separated string, "2,3,5"
You may not assume the inputs are sorted.

Output
A Truthy value if a triangle could have the sides with the lengths given, Falsy otherwise.

Test cases
1, 1, 1 -> Truthy
1, 2, 3 -> Falsy
2, 1, 3 -> Falsy
1, 3, 2 -> Falsy
3, 2, 1 -> Falsy
3, 1, 2 -> Falsy
2, 2, 2 -> Truthy
3, 4, 5 -> Truthy
3, 5, 4 -> Truthy
5, 3, 4 -> Truthy
5, 4, 3 -> Truthy
10, 9, 3 -> Truthy
100, 10, 10 -> Falsy

This is code-golf so shortest solution in bytes, wins. Consider upvoting this challenge if you have fun solving it and... Happy golfing!

*/

use std::cmp::*;

fn main() {
    assert_eq!(triangle(1, 1, 1), true);
    assert_eq!(triangle(1, 2, 3), false);
    assert_eq!(triangle(2, 1, 3), false);
    assert_eq!(triangle(1, 3, 2), false);
    assert_eq!(triangle(3, 2, 1), false);
    assert_eq!(triangle(3, 1, 2), false);
    assert_eq!(triangle(2, 2, 2), true);
    assert_eq!(triangle(3, 4, 5), true);
    assert_eq!(triangle(3, 5, 4), true);
    assert_eq!(triangle(5, 3, 4), true);
    assert_eq!(triangle(5, 4, 3), true);
    assert_eq!(triangle(10, 9, 3), true);
    assert_eq!(triangle(100, 10, 10), false);
    assert_eq!(triangle(2, 3, 4), true);
    assert_eq!(triangle(3, 4, 5), true);
    assert_eq!(triangle(4, 3, 8), false);
    assert_eq!(triangle(4, 5, 6), true);
    assert_eq!(triangle(3, 4, 6), true);
    assert_eq!(triangle(2, 5, 7), false);
    assert_eq!(triangle(2, 5, 9), false);
    assert_eq!(triangle(2, 9, 5), false);
    assert_eq!(triangle(9, 2, 5), false);
    assert_eq!(triangle(11, 12, 20), true);
    assert_eq!(triangle(14, 3, 12), true);
    assert_eq!(triangle(23, 4, 28), false);
    assert_eq!(triangle(21, 4, 25), false);
}

/*

@xnor

Checks if a+b+c > max(a,b,c)*2. If, say, c is the biggest one, this is equivalent to a+b+c>2*c, or a+b>c, which is want we want for the triangle inequality.

*/

fn triangle(a: usize, b: usize, c: usize) -> bool {
    (a + b + c) > max(max(a, b), c) * 2
}

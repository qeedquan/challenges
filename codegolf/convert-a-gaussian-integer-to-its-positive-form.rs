/*

We already have a challenge for computing the GCD of two Gaussian integers, but that challenge explicitly allows to choose any of the four possible values.

Your task now is to bring the Gaussian integer computed by the GCD in the following normal form:

The result differs from the original number by a factor of 1,i,-1 or -i
The result is zero, or the real part is positive
The imaginary part is non-negative

Input: A Gaussian integer (complex number with integer real and imaginary parts)
Output: The normal form (see above) of that Gaussian integer

Examples:
0 -> 0
5 -> 5
2i -> 2
1+i -> 1+i
1-i -> 1+i
3-5i -> 5+3i
-3+5i -> 5+3i
3+5i -> 3+5i
-3-5i -> 3+5i

Rules
You can use pairs instead of complex numbers for input/output
If your language has a built-in for this operation consider adding a non built-in solution as well
This is code-golf the shortest solution wins

*/

fn main() {
    assert_eq!(normal_form(0, 0), (0, 0));
    assert_eq!(normal_form(5, 0), (5, 0));
    assert_eq!(normal_form(0, 2), (2, 0));
    assert_eq!(normal_form(1, 1), (1, 1));
    assert_eq!(normal_form(3, -5), (5, 3));
    assert_eq!(normal_form(-3, 5), (5, 3));
    assert_eq!(normal_form(3, 5), (3, 5));
    assert_eq!(normal_form(-3, -5), (3, 5));
    assert_eq!(normal_form(-562, 52365), (52365, 562));
    assert_eq!(normal_form(0, -52365), (52365, 0));
}

fn normal_form(r: isize, i: isize) -> (isize, isize) {
    if ((r != 0 || i != 0) && r < 1) || i < 0 {
        normal_form(-i, r)
    } else {
        (r, i)
    }
}

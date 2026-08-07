/*

Description
In mathematics, a continued fraction is an expression obtained through an iterative process of representing a number as the sum of its integer part and the reciprocal of another number, then writing this other number as the sum of its integer part and another reciprocal, and so on.

A continued fraction is an expression of the form

            1
    x + ----------
               1
        y + -------
                  1
            z + ----
                 ...
and so forth, where x, y, z, and such are real numbers, rational numbers, or complex numbers. Using Gauss notation, this may be abbreviated as

[x; y, z, ...]
To convert a continued fraction to an ordinary fraction, we just simplify from the right side, which may be an improper fraction, one where the numerator is larger than the denominator.

Continued fractions can be decomposed as well, which breaks it down from an improper fraction to its Gauss notation. For example:

16        1
-- = 0 + ---
45        45
          --
          16
We can then begin to decompose this:

      1
0 + ----------------
              1
    2 + ------------
              1
        1 + --------
                1
            4 + -
                3
So the Gauss notation would be [0;2,1,4,3].

Your challenge today is to implement a program that can do two things in the realm of continued fractions:

Given a Gauss representation of a continued fraction, calculate the improper fraction.

Given an improper fraction, calculate the Gauss representation.

Challenge Inputs
45
--
16


[2;1,7]

7
-
3
Challenge Outputs
45
-- = [2;1,4,3]
16

          23
[2;1,7] = --
           8


7
- = [2;3]
3

Bonus
Display the continued fraction. Mega bonus if you use MathML or LaTeX.

Notes
https://en.wikipedia.org/wiki/Continued_fraction

http://www.cemc.uwaterloo.ca/events/mathcircles/2016-17/Fall/Junior78_Oct11_Soln.pdf

@CrazyMerlyn
Godspiral is correct. The pdf is wrong. In case of [2; 2, 1, 1] the pdf takes 1 + 1 = 1 and in case [2; 1, 7], the pdf forgets to take reciprocal of 8/7 before last step.

*/

fn main() {
    println!("{:?}", fraction_to_gauss(45, 16));
    println!("{:?}", fraction_to_gauss(7, 3));

    println!("{:?}", gauss_to_fraction(vec![2, 1, 7]));
    println!("{:?}", gauss_to_fraction(vec![2, 2, 1, 1]));
    println!("{:?}", gauss_to_fraction(vec![4, 2, 6, 7]));
}

fn fraction_to_gauss(mut a: isize, mut b: isize) -> Vec<isize> {
    let mut cf = vec![];
    while b > 0 {
        cf.push(a / b);
        (a, b) = (b, a % b);
    }
    cf
}

fn gauss_to_fraction(cf: Vec<isize>) -> (isize, isize) {
    let (mut a, mut b) = (0, 1);
    for i in (0..cf.len()).rev() {
        (a, b) = (b, a + (cf[i] * b));
    }
    (b, a)
}

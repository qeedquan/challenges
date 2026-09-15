/*

Challenge
Create a function or program that, when given an integer size, does the following:

If size is equal to 1, output

H H
HHH
H H
If size is greater than 1, output

X X
XXX
X X
where X is the output of the program/function for size - 1

(If you prefer, you may have the base case correspond to 0, so long as you specify in your answer)

Any of the following output formats are acceptable, whichever is more convenient for you:

A string of the required structure with any two distinct characters corresponding to H and space

A two-dimensional array with the required structure, with any two distinct values corresponding to H and space

An array/list of strings, with one line of the output in each string, with any two distinct values corresponding to H and space

Leading spaces are allowed, as long as there is a constant amount of leading spaces on each line. The two distinct output characters can be dependent on anything you choose, as long as they are different.

Specify what output format your code is returning.

Test Cases
1

H H
HHH
H H
2

H H   H H
HHH   HHH
H H   H H
H HH HH H
HHHHHHHHH
H HH HH H
H H   H H
HHH   HHH
H H   H H
3

H H   H H         H H   H H
HHH   HHH         HHH   HHH
H H   H H         H H   H H
H HH HH H         H HH HH H
HHHHHHHHH         HHHHHHHHH
H HH HH H         H HH HH H
H H   H H         H H   H H
HHH   HHH         HHH   HHH
H H   H H         H H   H H
H H   H HH H   H HH H   H H
HHH   HHHHHH   HHHHHH   HHH
H H   H HH H   H HH H   H H
H HH HH HH HH HH HH HH HH H
HHHHHHHHHHHHHHHHHHHHHHHHHHH
H HH HH HH HH HH HH HH HH H
H H   H HH H   H HH H   H H
HHH   HHHHHH   HHHHHH   HHH
H H   H HH H   H HH H   H H
H H   H H         H H   H H
HHH   HHH         HHH   HHH
H H   H H         H H   H H
H HH HH H         H HH HH H
HHHHHHHHH         HHHHHHHHH
H HH HH H         H HH HH H
H H   H H         H H   H H
HHH   HHH         HHH   HHH
H H   H H         H H   H H

This is code-golf, so the lowest byte count for each language wins!

*/

fn main() {
    for i in 0..4 {
        hf(i);
    }
}

/*

ported from @xnor solution

Uses the same template as other 3*3 fractal patterns
Sierpinski carpet
Fractal X
Fractal plus

*/

fn hf(n: u32) {
    println!("n={n}");
    if n < 1 {
        println!();
        return;
    }

    let l = 3isize.pow(n);
    for i in 0..l {
        let mut p = format!(" ");
        let mut s = format!("H");
        let mut j = i;
        for _ in 0..n {
            if (j % 3) & 1 == 0 {
                s = format!("{s}{p}{s}");
            } else {
                s = format!("{s}{s}{s}");
            }
            p = format!("{p}{p}{p}");
            j /= 3;
        }
        println!("{s}");
    }
    println!();
}

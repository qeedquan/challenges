/*

Definition
In Mathematics, Harmonic Sequence refers to a sequence where

a[n]=1/n

i.e. the nth term of the sequence equals the reciprocal of n.

Introduction
In this challenge, given a positive integer n as input, output the Partial Sum of first n terms of the Harmonic Sequence.

Input
You'll be given a positive integer (within the range of numbers supported by your language). It can be either of Signed and Unsigned (depends on you), since the challenge requires only positive integers.

You can take the input in any way except assuming it to be present in a predefined variable. Reading from file, terminal, modal window (prompt() in JavaScript) etc. is allowed. Taking the input as function argument is allowed as well.

Output
Your program should output the sum of the first n terms of the Harmonic Sequence as a float (or integer if the output is evenly divisible by 1) with precision of 5 significant figures, where n refers to the input. To convey the same in Mathematical jargon, you need to compute

Sum[i=1, n] 1/i

where n refers to the input.

You can output in any way except writing the output to a variable. Writing to screen, terminal, file, modal window (alert() in JavaScript) etc. is allowed. Outputting as function return value is allowed as well.

Additional Rules
The input number can be either of 0-indexed or 1-indexed. You must specify that in your post.

You must not use a built-in to calculate the partial sum of the first n elements. (Yeah, it's for you Mathematica!)

You must not abuse native number types to trivialize the problem.

Standard Loopholes apply.

Test Cases
The Test Cases assume the input to be 1-indexed

Input     Output
1         1
2         1.5
3         1.8333
4         2.0833
5         2.2833

Winning Criterion
This is code-golf, so the shortest code in bytes wins!

*/

fn main() {
    for i in 1..6 {
        println!("{}", harmonic(i));
    }
}

fn harmonic(n: isize) -> f64 {
    let mut r = 0.0;
    for i in 1..n + 1 {
        r += 1.0 / i as f64;
    }
    r
}

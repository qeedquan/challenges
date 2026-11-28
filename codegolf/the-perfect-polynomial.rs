/*

The coefficients of a perfect square polynomial can be calculated by the formula (ax)^2 + 2abx + b^2, where both a and b are integers.
The objective of this challenge is to create a program that not only can find if an input trinomial is a perfect square, but also find its square root binomial.
The input trinomial will be written in this format:

1 2 1

which symbolizes the perfect square number x^2+2x+1, since all 3 input numbers represent coefficients of the trinomial.
The outputs must be readable and understandable. To count as a perfect square in this challenge, a trinomial must have a and b as real integer numbers.
No fractions, decimals, irrational numbers or imaginary/complex numbers allowed in the final binomial. Make a program that accomplishes this, and since this is code-golf, the shortest code in bytes wins.

*/

fn main() {
    println!("{:?}", solve(1.0, 2.0, 1.0));
    println!("{:?}", solve(2.0, 4.0, 2.0));
    println!("{:?}", solve(9.0, 12.0, 4.0));
    println!("{:?}", solve(9.0, 12.0, -4.0));
}

/*

@user
Can be called as f(a,b,c). Output is in the form [<factor of x>, <constant>, True/False] (if it's False, then the first 2 values are meaningless).

*/

fn solve(a: f64, b: f64, c: f64) -> (f64, f64, bool) {
    let x = a.sqrt();
    let y = b / (x * 2.0);
    let z = (b * b) == (4.0 * a * c);
    (x, y, z)
}

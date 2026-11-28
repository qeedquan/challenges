/*

Estimate the partial derivatives of the scalar expression

d(a, b, c) = (a*b) + c

Here a, b, c are scalar inputs and d is the expression value.
Use the supplied positive step h and forward differences, such as

dd/da ~ (d(a+h, b, c) - d(a, b, c)) / h

The partial-derivative symbol measures sensitivity to one input with the others fixed.
Apply the same definition to b and c. Return a four-item tuple of Python floats: the original expression value,
then its numerical partial derivatives for a, b, and c.

Examples
Input: a=2.0, b=-3.0, c=10.0, h=0.001

Output: (4.0,-3.0,2.0,1.0)

Explanation: Changing one variable at a time recovers the local sensitivities of ab+c.

Input: a=0.0, b=0.0, c=0.0, h=0.01

Output: (0.0,0.0,0.0,1.0)

Input: a=0.5, b=1.25, c=-2.0, h=0.0001

Output: (-1.375,1.25,0.5,1.0)

Hint 1
enumerate can track which input receives a perturbation.

Hint 2
list.copy keeps each perturbed input list separate from the original.

Requirements
Use 64-bit floating-point arithmetic; NumPy is available.
Return forward-difference estimates using the supplied h, not analytic derivatives.
Keep the partials in a, b, c order.
Constraints
a, b, and c are finite numbers.
h is a finite positive number.
All expression values and returned partial derivatives must be finite.

*/

fn main() {
    println!("{:?}", scalar_expression_partials(2.0, -3.0, 10.0, 0.001));
    println!("{:?}", scalar_expression_partials(0.0, 0.0, 0.0, 0.01));
    println!("{:?}", scalar_expression_partials(0.5, 1.25, -2.0, 0.0001));
}

fn scalar_expression_partials(a: f64, b: f64, c: f64, h: f64) -> (f64, f64, f64, f64) {
    let v = d(a, b, c);
    let da = (d(a + h, b, c) - v) / h;
    let db = (d(a, b + h, c) - v) / h;
    let dc = (d(a, b, c + h) - v) / h;
    return (v, da, db, dc);
}

fn d(a: f64, b: f64, c: f64) -> f64 {
    return (a * b) + c;
}

/*

As the title says! Raise one complex number to the power of another. (a+bi)^(c+di)
(using the principal branch of the complex logarithm)

Requires four inputs a, b, c, d. You can combine a, b, c, d into respective vectors/arrays (e.x. C([a, b], [c, d]))

Built-in complex arithmetic is not allowed. Code the solution yourself!
(Built-in functions are any functions that perform arithmetic on complex vectors. e.x. quaternions, complex libraries, languages where complex numbers are a type. If your language does not have an only-real type then arithmetic operators can only be used on the reals.)
Functions are treated as the program:

function x(arg){
    ...
    return output;
}
is the same as

arg = getInput();
...
print(output);
Smallest byte length wins.

EXAMPLES:
(1+1.5i)^(2+2.5i) ≈ −0.266-0.082i
(e+1i)^(π+1i) ≈ −11.213 + 16.386i
(1+1i)^(1+1i) ≈ 0.274 + 0.584i
(-1+i)^(1+i) ≈ -0.121 + 0.057i

*/

use std::f64::consts::E;
use std::f64::consts::PI;

fn main() {
    println!("{:?}", cexp(1.0, 1.5, 2.0, 2.5));
    println!("{:?}", cexp(E, 1.0, PI, 1.0));
    println!("{:?}", cexp(1.0, 1.0, 1.0, 1.0));
    println!("{:?}", cexp(-1.0, 1.0, 1.0, 1.0));
}

fn cexp(a: f64, b: f64, c: f64, d: f64) -> (f64, f64) {
    let s = (a * a) + (b * b);
    let p = b.atan2(a);
    let r = s.powf(c / 2.0) / (d * p).exp();
    let u = (c * p) + (d * s.ln()) / 2.0;
    (r * u.cos(), r * u.sin())
}

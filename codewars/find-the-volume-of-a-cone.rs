/*

Find the volume of a cone whose radius and height are provided as parameters to the function volume. Use the value of PI provided by your language (for example: Math.PI in JS, math.pi in Python or Math::PI in Ruby) and round down the volume to an Interger.

If you complete this kata and there are no issues, please remember to give it a ready vote and a difficulty rating. :)

*/

use std::f64::consts::PI;

fn main() {
    println!("{}", volume(5.0, 40.0));
}

fn volume(r: f64, h: f64) -> f64 {
    (1.0 / 3.0) * r * r * PI * h
}

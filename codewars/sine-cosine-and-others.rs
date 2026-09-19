/*

Given value of sine,implement function which will return sine,cosine,tangent,and cotangent in list. order must be same as in the description and every number must be rounded to 2 decimal places.If tangent or cotangent can not be calculated just don't contain them in result list.

Trigonometry - https://en.wikipedia.org/wiki/Trigonometry

*/

use std::f64::consts::PI;

fn main() {
    println!("{:?}", trigonometry(0.0));
    println!("{:?}", trigonometry(PI / 2.0));
    println!("{:?}", trigonometry(PI));
}

fn trigonometry(x: f64) -> Vec<f64> {
    let mut r = vec![x.sin(), x.cos()];
    if r[1] != 0.0 {
        r.push(r[0] / r[1]);
    }
    if r[0] != 0.0 {
        r.push(r[1] / r[0]);
    }
    r
}

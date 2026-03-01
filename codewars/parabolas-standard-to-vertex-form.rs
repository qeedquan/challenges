/*

There are two main ways to write out a quadratic function, standard form: f(x) = a(x^2)+bx+c and vertex form:
f(x) = a((x-h)^2) + k (where (h,k) are the coordinates of the vertex of the parabola).

Your Task is to write a function getVertex that takes three parameters a, b, and c and returns an array of two numbers [h,k] such that a(x^2)+bx+c = a((x-h)^2) + k.

Note: Make sure it works for a values other than 1.

*/

fn main() {
    let n = 100;
    for i in -n..n {
        for j in -n..n {
            for k in -n..n {
                let a = f64::from(i);
                let b = f64::from(j);
                let c = f64::from(k);
                let (h, k) = vertex(a, b, c);
                for l in -n..n {
                    let x = f64::from(l);
                    let u = (a * x * x) + (b * x) + c;
                    let v = a * ((x - h) * (x - h)) + k;
                    if (u - v).abs() >= 1e-6 {
                        println!("{} {}", u, v);
                    }
                }
            }
        }
    }
}

fn vertex(a: f64, b: f64, c: f64) -> (f64, f64) {
    let h = -b / (2.0 * a);
    let k = c - (b * b) / (4.0 * a);
    (h, k)
}

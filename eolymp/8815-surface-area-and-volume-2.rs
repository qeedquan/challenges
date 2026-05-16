/*

Find the surface area and volume of the cube by the length of its edge.

s = 6a^2
v = a^3

Input
The length of cube's edge a (a≤10^6).

Output
Print the surface area and volume of the cube.

Examples
Input #1
3

Answer #1
54 27

*/

fn main() {
    println!("{:?}", solve(3.0));
}

fn solve(a: f64) -> (f64, f64) {
    (6.0 * a * a, a * a * a)
}

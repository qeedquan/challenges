/*

A cone is located in 3D space such that its base of radius r lies in the z=0 plane,
with its center at (0, 0, 0) . The tip (vertex) of the cone is at (0,0,h).
Two points are given on the surface of the cone in conic coordinates.

The conic coordinates of a point p on the surface of the cone are described by a pair (d,A),
where d is the distance from the tip of the cone to p, and A (A<360) is the angle in degrees
between the plane y=0 and the plane passing through (0,0,0), (0,0,h) and p, measured counterclockwise from the direction of the x-axis.

https://static.e-olymp.com/content/63/6389b87c766eb6bfc1ced600a3ab9dca6efbfb0a.jpg

Given two points p1=(d1, A1) and p2=(d2, A2) in conic coordinates, find the shortest distance between p1 and p2 measured along the surface of the cone.

Output
For each test case, print the shortest distance between p1 and p2
on the surface of the cone, rounded to 2 decimal places, on a separate line.

Examples

Input #1
3.0 4.0 2.0 0.0 4.0 0.0
3.0 4.0 2.0 90.0 4.0 0.0
6.0 8.0 2.14 75.2 9.58 114.3
3.0 4.0 5.0 0.0 5.0 90.0

Answer #1
2.00
3.26
7.66
4.54

*/

use std::f64::consts::PI;

fn main() {
    println!("{:.2}", solve(3.0, 4.0, 2.0, 0.0, 4.0, 0.0));
    println!("{:.2}", solve(3.0, 4.0, 2.0, 90.0, 4.0, 0.0));
    println!("{:.2}", solve(6.0, 8.0, 2.14, 75.2, 9.58, 114.3));
    println!("{:.2}", solve(3.0, 4.0, 5.0, 0.0, 5.0, 90.0));
}

/*

https://en.wikipedia.org/wiki/Law_of_cosines

The distance between two points on a cone can be treated as one of the side length of a triangle that is not right-angled

*/

fn solve(r: f64, h: f64, d1: f64, a1: f64, d2: f64, a2: f64) -> f64 {
    let a1 = deg2rad(a1);
    let a2 = deg2rad(a2);

    let mut da = (a2 - a1).abs();
    if da > PI {
        da = (2.0 * PI) - da;
    }

    let phi = da * r / r.hypot(h);
    ((d1 * d1) + (d2 * d2) - (2.0 * d1 * d2 * phi.cos())).sqrt()
}

fn deg2rad(x: f64) -> f64 {
    x * PI / 180.0
}

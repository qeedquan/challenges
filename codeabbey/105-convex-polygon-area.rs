/*

You have probably already wrote the program for calculating Area of Triangle - let us now get acquainted with the extention of this problem - the calculation of area for arbitrary convex polygon.

Polygon is called convex if each of its angles is less than PI (e.g. 180 degrees), or in other words, if any line connecting any pair of points belonging to it lies completely inside. This somewhat simplifies handling of such shapes.

You need to reduce this problem to one with triangles. We hope that pictures above may give you idea on three different approaches to do this.

Input data contain the number of vertices of the polygon.
Next lines contain a pair of numbers each - X and Y coordinates for the vertex (in correct CCW order).
Answer should contain the area of the shape surrounded by these points.

Example:

input data:
5
51 9
77 10
92 71
62 84
29 94

answer:
3274.5

*/

#[derive(Copy, Clone)]
struct Point {
    x: f64,
    y: f64,
}

fn main() {
    println!(
        "{}",
        area(&[
            Point { x: 51.0, y: 9.0 },
            Point { x: 77.0, y: 10.0 },
            Point { x: 92.0, y: 71.0 },
            Point { x: 62.0, y: 84.0 },
            Point { x: 29.0, y: 94.0 },
        ]),
    );
}

fn area(p: &[Point]) -> f64 {
    return shoelace(p).abs();
}

fn shoelace(p: &[Point]) -> f64 {
    let n = p.len();
    if n < 3 {
        return 0.0;
    }

    let mut s = 0.0;
    for i in 0..n {
        s += wedge(p[i], p[(i + 1) % n]);
    }
    return s / 2.0;
}

fn wedge(p: Point, q: Point) -> f64 {
    return (p.x * q.y) - (p.y * q.x);
}

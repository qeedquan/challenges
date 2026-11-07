/*

Given 3 points a, b, c

            c

                     b
  a

Find the shortest distance from point c to a straight line that passes through points a and b

Notes

all points are of the form [x,y] where x >= 0 and y >= 0
if a and b are the same then just return distance between a and c
use Euclidean distance

*/

struct Point {
    x: f64,
    y: f64,
}

fn main() {
    println!(
        "{}",
        distance(
            Point { x: 0.0, y: 0.0 },
            Point { x: 1.0, y: 0.0 },
            Point { x: 0.5, y: 0.0 }
        )
    );

    println!(
        "{}",
        distance(
            Point { x: 0.0, y: 0.0 },
            Point { x: 1.0, y: 0.0 },
            Point { x: 0.5, y: 13.0 }
        )
    );
}

// https://en.wikipedia.org/wiki/Distance_from_a_point_to_a_line
fn distance(a: Point, b: Point, c: Point) -> f64 {
    let (x1, y1) = (a.x, a.y);
    let (x2, y2) = (b.x, b.y);
    let (x0, y0) = (c.x, c.y);

    let n1 = (y2 - y1) * x0;
    let n2 = (x2 - x1) * y0;
    let n3 = x2 * y1;
    let n4 = y2 * x1;
    let n = (n1 - n2 + n3 - n4).abs();

    let d1 = (y2 - y1) * (y2 - y1);
    let d2 = (x2 - x1) * (x2 - x1);
    let d = (d1 + d2).sqrt();

    if d == 0.0 {
        return 0.0;
    }
    return n / d;
}

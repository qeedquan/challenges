/*

https://imgur.com/hpDQY8o

The medians of a triangle are the segments that unit the vertices with the midpoint of their opposite sides. The three medians of a triangle intersect at the same point, called the barycenter or the centroid. Given a triangle, defined by the cartesian coordinates of its vertices we need to localize its barycenter or centroid.

The function bar_triang() or barTriang or bar-triang, receives the coordinates of the three vertices A, B and C  as three different arguments and outputs the coordinates of the barycenter O in an array [xO, yO]

This is how our asked function should work: the result of the coordinates should be expressed up to four decimals, (rounded result).

You know that the coordinates of the barycenter are given by the following formulas.

XO = (XA + XB + XC) / 3
YO = (YA + YB + YC) / 3

For additional information about this important point of a triangle see at: (https://en.wikipedia.org/wiki/Centroid)

Let's see some cases:

bar_triang([4, 6], [12, 4], [10, 10]) ------> [8.6667, 6.6667]

bar_triang([4, 2], [12, 2], [6, 10] ------> [7.3333, 4.6667]
The given points form a real or a degenerate triangle but in each case the above formulas can be used.

Enjoy it and happy coding!!

*/

#[derive(Debug)]
struct Vec2 {
    x: f64,
    y: f64,
}

fn main() {
    println!(
        "{:?}",
        barycenter(
            Vec2 { x: 4.0, y: 6.0 },
            Vec2 { x: 12.0, y: 4.0 },
            Vec2 { x: 10.0, y: 10.0 }
        )
    );
    println!(
        "{:?}",
        barycenter(
            Vec2 { x: 4.0, y: 2.0 },
            Vec2 { x: 12.0, y: 2.0 },
            Vec2 { x: 6.0, y: 10.0 }
        )
    );
}

fn barycenter(a: Vec2, b: Vec2, c: Vec2) -> Vec2 {
    Vec2 {
        x: (a.x + b.x + c.x) / 3.0,
        y: (a.y + b.y + c.y) / 3.0,
    }
}

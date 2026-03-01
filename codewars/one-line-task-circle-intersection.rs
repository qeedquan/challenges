/*

Task
Given two congruent circles a and b of radius r, return the area of their intersection rounded down to the nearest integer.

Code Limit
Javascript: Less than 94 characters.

Python: Less than 128 characters.

Example
For c1 = [0, 0], c2 = [7, 0] and r = 5,

the output should be 14.

*/

struct Point {
    x: f64,
    y: f64,
}

fn main() {
    assert_eq!(
        solve(Point { x: 0.0, y: 0.0 }, Point { x: 7.0, y: 0.0 }, 5.0),
        14
    );
    assert_eq!(
        solve(Point { x: 0.0, y: 0.0 }, Point { x: 0.0, y: 10.0 }, 10.0),
        122
    );
    assert_eq!(
        solve(Point { x: 5.0, y: 6.0 }, Point { x: 5.0, y: 6.0 }, 3.0),
        28
    );
    assert_eq!(
        solve(Point { x: -5.0, y: 0.0 }, Point { x: 5.0, y: 0.0 }, 3.0),
        0
    );
    assert_eq!(
        solve(
            Point { x: 10.0, y: 20.0 },
            Point { x: -5.0, y: -15.0 },
            20.0
        ),
        15
    );
    assert_eq!(
        solve(
            Point { x: -7.0, y: 13.0 },
            Point { x: -25.0, y: -5.0 },
            17.0
        ),
        132
    );
    assert_eq!(
        solve(
            Point { x: -20.0, y: -4.0 },
            Point { x: -40.0, y: 29.0 },
            7.0
        ),
        0
    );
    assert_eq!(
        solve(
            Point { x: 38.0, y: -18.0 },
            Point { x: 46.0, y: -29.0 },
            10.0
        ),
        64
    );
    assert_eq!(
        solve(
            Point { x: -29.0, y: 33.0 },
            Point { x: -8.0, y: 13.0 },
            15.0
        ),
        5
    );
    assert_eq!(
        solve(
            Point { x: -12.0, y: 20.0 },
            Point { x: 43.0, y: -49.0 },
            23.0
        ),
        0
    );
}

fn solve(a: Point, b: Point, r: f64) -> isize {
    area(a, b, r) as isize
}

fn area(a: Point, b: Point, r: f64) -> f64 {
    let d = distance(a, b);
    let r = 2.0 * r;
    if d > r {
        return 0.0;
    }
    return (r * r * (d / r).acos() - d * (r * r - d * d).sqrt()) / 2.0;
}

fn distance(a: Point, b: Point) -> f64 {
    let dx = a.x - b.x;
    let dy = a.y - b.y;
    dx.hypot(dy)
}

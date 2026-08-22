/*

Task
Write a program/function that when given three 2d points in cartesian coordinates as input outputs a truthy value if they are collinear otherwise a falsey value

Three points are said to be collinear if there exists a straight line that passes through all the points

You may assume that the coordinates of the three points are integers and that the three points are distinct.

Scoring
This is code-golf so shortest bytes wins

Sample Testcases
(1, 1), (2, 2), (3, 3) -> Truthy
(1, 1), (2, 2), (10, 10) -> Truthy
(10, 1), (10, 2), (10, 3) -> Truthy
(1, 10), (2, 10), (3, 10) -> Truthy
(1, 1), (2, 2), (3, 4) -> Falsey
(1, 1), (2, 0), (2, 2) -> Falsey
(-5, 70), (2, 0), (-1, 30) -> Truthy
(460, 2363), (1127, 2392), (-1334, 2285) -> Truthy
(-789, -215), (-753, -110), (518, -780) -> Falsey
(227816082, 4430300), (121709952, 3976855), (127369710, 4001042) -> Truthy
(641027, 3459466), (475989, 3458761), (-675960, 3453838) -> Falsey

*/

struct Point {
    x: isize,
    y: isize,
}

fn main() {
    assert_eq!(
        collinear(
            Point { x: 1, y: 1 },
            Point { x: 2, y: 2 },
            Point { x: 3, y: 3 },
        ),
        true
    );

    assert_eq!(
        collinear(
            Point { x: 1, y: 1 },
            Point { x: 2, y: 2 },
            Point { x: 10, y: 10 },
        ),
        true
    );

    assert_eq!(
        collinear(
            Point { x: 10, y: 1 },
            Point { x: 10, y: 2 },
            Point { x: 10, y: 3 },
        ),
        true
    );

    assert_eq!(
        collinear(
            Point { x: 1, y: 10 },
            Point { x: 2, y: 10 },
            Point { x: 3, y: 10 },
        ),
        true
    );

    assert_eq!(
        collinear(
            Point { x: 1, y: 1 },
            Point { x: 2, y: 2 },
            Point { x: 3, y: 4 },
        ),
        false
    );

    assert_eq!(
        collinear(
            Point { x: 1, y: 1 },
            Point { x: 2, y: 2 },
            Point { x: 3, y: 4 },
        ),
        false
    );

    assert_eq!(
        collinear(
            Point { x: 1, y: 1 },
            Point { x: 2, y: 0 },
            Point { x: 2, y: 2 },
        ),
        false
    );

    assert_eq!(
        collinear(
            Point { x: -5, y: 70 },
            Point { x: 2, y: 0 },
            Point { x: -1, y: 30 },
        ),
        true
    );

    assert_eq!(
        collinear(
            Point { x: 460, y: 2363 },
            Point { x: 1127, y: 2392 },
            Point { x: -1334, y: 2285 },
        ),
        true
    );

    assert_eq!(
        collinear(
            Point { x: -789, y: -215 },
            Point { x: -753, y: -110 },
            Point { x: 518, y: -780 },
        ),
        false
    );

    assert_eq!(
        collinear(
            Point {
                x: 227816082,
                y: 4430300
            },
            Point {
                x: 121709952,
                y: 3976855
            },
            Point {
                x: 127369710,
                y: 4001042
            },
        ),
        true
    );

    assert_eq!(
        collinear(
            Point {
                x: 641027,
                y: 3459466
            },
            Point {
                x: 475989,
                y: 3458761
            },
            Point {
                x: -675960,
                y: 3453838
            },
        ),
        false
    );
}

fn collinear(p0: Point, p1: Point, p2: Point) -> bool {
    let m = [[p0.x, p0.y, 1], [p1.x, p1.y, 1], [p2.x, p2.y, 1]];
    det3x3(m) == 0
}

fn det3x3(m: [[isize; 3]; 3]) -> isize {
    let c00 = m[1][1] * m[2][2] - m[1][2] * m[2][1];
    let c01 = m[1][2] * m[2][0] - m[1][0] * m[2][2];
    let c02 = m[1][0] * m[2][1] - m[1][1] * m[2][0];
    (m[0][0] * c00) + (m[0][1] * c01) + (m[0][2] * c02)
}

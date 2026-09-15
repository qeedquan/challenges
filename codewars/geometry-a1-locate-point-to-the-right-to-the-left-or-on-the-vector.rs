/*

Task
Your task is to determine the relationship between the given point and the vector. Direction of the vector is important! To determine if the point is to the left or to the right, you should imagine yourself standing at the beginning of the vector and looking at the end of the vector.

Arguments
You are given coordinates of a point and coordinates of a vector on 2D plane:

point = [x, y]

vector = [[x, y], [x, y]] (two points, direction is from first to second)

Vectors always have non-zero length, so you don't have to check for that at this point.

Return
Your function must return:

-1 if the point is to the left of the vector,

0 if the point is on the same line as vector,

1 if the point is to the right of the vector.


Do not repeat yourself!
You can consider re-using solution of this kata in some of the next Geometry katas:

Geometry A-1.1: Similar kata with precision handling and a check for zero vectors
Geometry A-3: Checking if point belongs to the vector
Geometry B-1: Is point inside or outside a triangle?

*/

use std::ops::Sub;

#[derive(Debug, Copy, Clone)]
struct Point {
    x: f64,
    y: f64,
}

impl Sub<Point> for Point {
    type Output = Self;
    fn sub(self, other: Point) -> Point {
        Point {
            x: self.x - other.x,
            y: self.y - other.y,
        }
    }
}

fn main() {
    let vector = [Point { x: 0.0, y: 0.0 }, Point { x: 1.0, y: 1.0 }];
    assert_eq!(point_vs_vector(Point { x: 0.0, y: 1.0 }, vector), -1);
    assert_eq!(point_vs_vector(Point { x: 2.0, y: 2.0 }, vector), 0);
    assert_eq!(point_vs_vector(Point { x: 2.0, y: 0.0 }, vector), 1);
}

fn point_vs_vector(point: Point, vector: [Point; 2]) -> isize {
    let value = wedge(vector[1] - vector[0], point - vector[1]);
    if value < 0.0 {
        -1
    } else if value > 0.0 {
        1
    } else {
        0
    }
}

fn wedge(vector1: Point, vector2: Point) -> f64 {
    (-vector1.x * vector2.y) + (vector1.y * vector2.x)
}

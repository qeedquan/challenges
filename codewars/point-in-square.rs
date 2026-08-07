/*

Task: estimate whether a point (x, y) lies in a square with the side length (d).

Preconditions:

the center of the square is at the coordinates (0, 0);
the length of the square side is greater than 0;
the sides of the square are parallel to the coordinate lines;
the point on the border of the square is considered to be inside the square.

*/

fn main() {
    assert_eq!(point_in_square(2.0, 2.0, 4.0), true);
    assert_eq!(point_in_square(-2.0, 2.0, 4.0), true);
    assert_eq!(point_in_square(2.0, -2.0, 4.0), true);
    assert_eq!(point_in_square(-2.0, -2.0, 4.0), true);
    assert_eq!(point_in_square(0.0, 2.0, 4.0), true);
    assert_eq!(point_in_square(2.0, 0.0, 4.0), true);
    assert_eq!(point_in_square(0.0, -2.0, 4.0), true);
    assert_eq!(point_in_square(-2.0, 0.0, 4.0), true);
    assert_eq!(point_in_square(1.0, 1.0, 4.0), true);
    assert_eq!(point_in_square(-1.0, -1.0, 4.0), true);
    assert_eq!(point_in_square(-1.0, 1.0, 4.0), true);
    assert_eq!(point_in_square(1.0, -1.0, 4.0), true);
    assert_eq!(point_in_square(0.0, 0.0, 4.0), true);

    assert_eq!(point_in_square(3.0, 3.0, 4.0), false);
    assert_eq!(point_in_square(-3.0, 3.0, 4.0), false);
    assert_eq!(point_in_square(3.0, -3.0, 4.0), false);
    assert_eq!(point_in_square(-3.0, -3.0, 4.0), false);
    assert_eq!(point_in_square(0.0, 3.0, 4.0), false);
    assert_eq!(point_in_square(3.0, 0.0, 4.0), false);
    assert_eq!(point_in_square(0.0, -3.0, 4.0), false);
    assert_eq!(point_in_square(-3.0, 0.0, 4.0), false);
}

fn point_in_square(x: f64, y: f64, d: f64) -> bool {
    let d = d / 2.0;
    (-d <= x && x <= d) && (-d <= y && y <= d)
}

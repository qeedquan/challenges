/*

Task
Your task is to check whether a segment is completely in one quadrant or it crosses more. Return true if the segment lies in two or more quadrants. If the segment lies within only one quadrant, return false.

There are two parameters: A (coord) and B (coord), the endpoints defining the segment AB.

No coordinate will be zero; expect that all X and Y are positive or negative.

Examples
This whole segment is in the first quadrant.
[(1, 2), (3, 4)] -> false

https://i.ibb.co/FbQTxKN/image.png

This segment intersects the Y axis, therefore being in two quadrants: I and II.
[(9, 3), (-1, 6)] -> true

https://i.ibb.co/ZHtgfw2/image.png

This segment is completely in the second quadrant.
[(-1, 6), (-9, 1)] -> false

https://i.ibb.co/x7VvdRn/image.png

Predefined
There is a class named coord/Coord (see in code). It has the following members:

(constructor): Constructs the coordinate
x (number): The X coordinate
y (number): The Y coordinate
x (number): The X coordinate
y (number): The Y coordinate
equal (bool): Compares two coordinates if they're the same
c (coord): The coordinate to compare with
toString (string): Turns coordinate into string

*/

fn main() {
    assert_eq!(crosses((1, 2), (3, 4)), false);
    assert_eq!(crosses((9, 3), (-1, 6)), true);
    assert_eq!(crosses((-1, 6), (-9, 1)), false);
}

fn crosses(p1: (isize, isize), p2: (isize, isize)) -> bool {
    quadrant(p1.0, p1.1) != quadrant(p2.0, p2.1)
}

fn quadrant(x: isize, y: isize) -> isize {
    match x | y {
        _ if (x >= 0 && y >= 0) => 1,
        _ if (x < 0 && y >= 0) => 2,
        _ if (x < 0 && y < 0) => 3,
        _ => 4,
    }
}

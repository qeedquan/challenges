/*

Andrey Sergeevich and Vitaly Borisovich decided to start breeding flowers.
Andrei Sergeyevich planted a circle of daisies on the lawn in front of the main building, and Vitaly Borisovich planted a circle of dandelions.
Viktor Alexandrovich and Natalia Mikhailovna decided to water the flowers every morning.
To evenly distribute the work, they decided that each of them will water exactly half of the daisies and exactly half of the dandelions.
At the same time, in order not to get confused, they decided to divide the flowers into appropriate parts by a straight fence.

Help Victor Aleksandrovich and Natalia Mikhailovna to divide the flower garden into two parts.

Input
First line contains three integers: x1, y1 and r1 - the coordinates of the centre and the radius of the circle of daisies.
Second line contains three integers: x2, y2 and r2 - the coordinates of the centre and the radius of the circle of dandelions.

Coordinates are not more than 10^4 by absolute value. The radii are positive and do not exceed 10^4.

Output
Print four integers xa, ya, xb and yb that do not exceed 10^9 by absolute value.

The desired line passes through the different points (xa,ya) and (xb,yb).

Examples
Input #1
1 0 3
2 0 3
Answer #1
1 0
2 0

Input #2
2 2 1
2 2 3

Answer #2
2 2
3 2

*/

fn main() {
    assert_eq!(solve(1, 0, 3, 2, 0, 3), (1, 0, 2, 0));
    assert_eq!(solve(2, 2, 1, 2, 2, 3), (2, 2, 3, 2));
}

fn solve(
    x1: isize,
    y1: isize,
    _r1: isize,
    x2: isize,
    y2: isize,
    _r2: isize,
) -> (isize, isize, isize, isize) {
    if x1 == x2 && y1 == y2 {
        return (x1, y1, x1 + 1, y1);
    }
    return (x1, y1, x2, y2);
}

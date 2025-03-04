/*

Given equation of two lines in the format Ax+By=C, determine their intersection point. If they are parallel print 'parallel' without quotes. For input/output format refer sample input/output.

Input
1x+1y=1
1x-1y=1

Output
(1.00,0.00)

Input
0x+1y=0
1x+0y=0

Output
(0.00,0.00)
-1000000 <= A,B,C <= 1000000.

Note their intersection point may not be integer. Print upto two decimal places.
Shortest solution wins.

*/

fn main() {
    assert_eq!(intersect(1.0, 1.0, -1.0, 1.0, -1.0, -1.0), (1.0, 0.0));
    assert_eq!(intersect(0.0, 1.0, 0.0, 1.0, 0.0, 0.0), (0.0, 0.0));
}

fn intersect(a1: f64, b1: f64, c1: f64, a2: f64, b2: f64, c2: f64) -> (f64, f64) {
    let d = (a1 * b2) - (a2 * b1);
    if d != 0.0 {
        let x = (b1 * c2) - (b2 * c1);
        let y = (c1 * a2) - (c2 * a1);
        (x / d, y / d)
    } else {
        (f64::NAN, f64::NAN)
    }
}

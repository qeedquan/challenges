/*


Description
You need to find the area that two rectangles overlap. The section you need to output the area of would be the blue lined section here: http://i.imgur.com/brZjYe5.png

If the two rectangles do not overlap, the resultant area should be 0.

Input
There will be two lines of input. On each line are the x and y positions (separated by a comma) of each opposing corner (each corner co-ordinate separated by a space). The co-ordinates can have decimals, and can be negative.

Output
The area of the overlapping section of the two rectangles, including any decimal part.

Challenge Inputs
1:

0,0 2,2
1,1 3,3
2:

-3.5,4 1,1
1,3.5 -2.5,-1
3:

-4,4 -0.5,2
0.5,1 3.5,3
Expected Ouputs
1:

1.0
2:

8.75
3:

0.0
Bonus
Make this work with any number of rectangles, calculating the area of where all input rectangles overlap. The input will define a rectangle on each line the same way, but there can be any amount of lines of input now.

Bonus Input
-3,0 1.8,4
1,1 -2.5,3.6
-4.1,5.75 0.5,2
-1.0,4.6 -2.9,-0.8
Bonus Expected Output
2.4
Finally
Have a good challenge idea?

Consider submitting it to r/dailyprogrammer_ideas

*/

fn main() {
    assert_allclose(area(&[&[0.0, 0.0, 2.0, 2.0], &[1.0, 1.0, 3.0, 3.0]]), 1.0);
    assert_allclose(
        area(&[&[-3.5, 4.0, 1.0, 1.0], &[1.0, 3.5, -2.5, -1.0]]),
        8.75,
    );
    assert_allclose(area(&[&[-4.0, 4.0, -0.5, 2.0], &[0.5, 1.0, 3.5, 3.0]]), 0.0);
    assert_allclose(
        area(&[
            &[-3.0, 0.0, 1.8, 4.0],
            &[1.0, 1.0, -2.5, 3.6],
            &[-4.1, 5.75, 0.5, 2.0],
            &[-1.0, 4.6, -2.9, -0.8],
        ]),
        2.4,
    );
}

fn assert_allclose(value0: f64, value1: f64) {
    assert_eq!((value0 - value1).abs() < 1e-12, true);
}

fn area(rects: &[&[f64; 4]]) -> f64 {
    let mut overlap = [f64::MIN, f64::MIN, f64::MAX, f64::MAX];
    for rect in rects {
        overlap[0] = f64::max(overlap[0], f64::min(rect[0], rect[2]));
        overlap[1] = f64::max(overlap[1], f64::min(rect[1], rect[3]));
        overlap[2] = f64::min(overlap[2], f64::max(rect[0], rect[2]));
        overlap[3] = f64::min(overlap[3], f64::max(rect[1], rect[3]));
    }
    let dx = overlap[2] - overlap[0];
    let dy = overlap[3] - overlap[1];
    f64::max(dx * dy, 0.0)
}

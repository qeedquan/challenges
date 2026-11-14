/*

Given a 2D integer array circles where circles[i] = [xi, yi, ri] represents the center (xi, yi) and radius ri of the ith circle drawn on a grid,
return the number of lattice points that are present inside at least one circle.

Note:

A lattice point is a point with integer coordinates.
Points that lie on the circumference of a circle are also considered to be inside it.

Example 1:
https://assets.leetcode.com/uploads/2022/03/02/exa-11.png
Input: circles = [[2,2,1]]
Output: 5
Explanation:
The figure above shows the given circle.
The lattice points present inside the circle are (1, 2), (2, 1), (2, 2), (2, 3), and (3, 2) and are shown in green.
Other points such as (1, 1) and (1, 3), which are shown in red, are not considered inside the circle.
Hence, the number of lattice points present inside at least one circle is 5.

Example 2:
https://assets.leetcode.com/uploads/2022/03/02/exa-22.png
Input: circles = [[2,2,2],[3,4,1]]
Output: 16
Explanation:
The figure above shows the given circles.
There are exactly 16 lattice points which are present inside at least one circle. 
Some of them are (0, 2), (2, 0), (2, 4), (3, 2), and (4, 4).

Constraints:

1 <= circles.length <= 200
circles[i].length == 3
1 <= xi, yi <= 100
1 <= ri <= min(xi, yi)

Hint 1
For each circle, how can you check whether or not a lattice point lies inside it?

Hint 2
Since you need to reduce the search space, consider the minimum and maximum possible values of the coordinates of a lattice point contained in any circle.

*/

use std::cmp::max;

fn main() {
    assert_eq!(count(&[[2, 2, 1]]), 5);
    assert_eq!(count(&[[2, 2, 2], [3, 4, 1]]), 16);
}

fn count(p: &[[isize; 3]]) -> isize {
    let (mut mx, mut my) = (0, 0);
    for c in p {
        mx = max(mx, c[0] + c[2]);
        my = max(my, c[1] + c[2]);
    }

    let mut r = 0;
    for x in 0..=mx {
        for y in 0..=my {
            for c in p {
                let dx = x - c[0];
                let dy = y - c[1];
                if dx * dx + dy * dy <= c[2] * c[2] {
                    r += 1;
                    break;
                }
            }
        }
    }
    r
}

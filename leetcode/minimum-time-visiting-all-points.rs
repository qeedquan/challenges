/*

On a 2D plane, there are n points with integer coordinates points[i] = [xi, yi]. Return the minimum time in seconds to visit all the points in the order given by points.

You can move according to these rules:

In 1 second, you can either:
move vertically by one unit,
move horizontally by one unit, or
move diagonally sqrt(2) units (in other words, move one unit vertically then one unit horizontally in 1 second).
You have to visit the points in the same order as they appear in the array.
You are allowed to pass through points that appear later in the order, but these do not count as visits.
 
Example 1:

Input: points = [[1,1],[3,4],[-1,0]]
Output: 7
Explanation: One optimal path is [1,1] -> [2,2] -> [3,3] -> [3,4] -> [2,3] -> [1,2] -> [0,1] -> [-1,0]   
Time from [1,1] to [3,4] = 3 seconds 
Time from [3,4] to [-1,0] = 4 seconds
Total time = 7 seconds

Example 2:

Input: points = [[3,2],[-2,2]]
Output: 5
 

Constraints:

points.length == n
1 <= n <= 100
points[i].length == 2
-1000 <= points[i][0], points[i][1] <= 1000

Hint:
To walk from point A to point B there will be an optimal strategy to walk?
Advance in diagonal as much as possible then after that go in straight line.

*/

fn main() {
    assert_eq!(
        mtvap(vec![
            Point { x: 1, y: 1 },
            Point { x: 3, y: 4 },
            Point { x: -1, y: 0 },
        ]),
        7
    );

    assert_eq!(mtvap(vec![Point { x: 3, y: 2 }, Point { x: -2, y: 2 },]), 5);
}

#[derive(Copy, Clone, PartialEq, Eq, Hash)]
struct Point {
    x: isize,
    y: isize,
}

fn mtvap(p: Vec<Point>) -> isize {
    let (mut r, n) = (0, p.len());
    for i in 1..n {
        r += distance(p[i - 1], p[i]);
    }
    r
}

fn distance(a: Point, b: Point) -> isize {
    let d = diagonal(a, b);
    let p = Point {
        x: a.x + d,
        y: a.y + d,
    };
    d.abs() + manhattan(p, b)
}

fn diagonal(a: Point, b: Point) -> isize {
    let dx = b.x - a.x;
    let dy = b.y - a.y;
    if dx.abs() < dy.abs() {
        dx
    } else {
        dy
    }
}

fn manhattan(a: Point, b: Point) -> isize {
    (b.x - a.x).abs() + (b.y - a.y).abs()
}

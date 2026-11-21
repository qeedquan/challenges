/*

Given two non-empty sets of points P,T={(x,y) | x,y∈Z}, find the point p∈P such that it is the "most isolated" from all points in T.
The "most isolated" point is defined as the point that maximizes the minimum distance to all points in a given set.

If multiple points are "most isolated", you must deterministically pick one of them. If no points are "most isolated", you must deterministically pick any point from P.

Scoring Criteria
Your score is your average asymptotic time complexity (if the complexity depends on the length of P and T, assume the lengths are the same).
If multiple answers have the same time complexity, your code size in bytes is the tie-breaker. Lowest score wins!

Worked Example
Consider P={(1,2),(3,4),(5,6)} and T={(2,6),(7,1),(7,5)}. The distance of each point in P to each point in T is

# dict is of structure {p: {t: distance(p,t)}}
{(1, 2): {(2, 6): 4.123105625617661,
          (7, 1): 6.082762530298219,
          (7, 5): 6.708203932499369},
 (3, 4): {(2, 6): 2.23606797749979,
          (7, 1): 5.0,
          (7, 5): 4.123105625617661},
 (5, 6): {(2, 6): 3.0,
          (7, 1): 5.385164807134504,
          (7, 5): 2.23606797749979}}

In this example, the point p∈P that is most isolated is the point (1,2), since its distances are maximal to each point in T.

Test Cases
# P, T -> output
[(1,2),(3,4),(5,6)], [(2,6),(7,1),(7,5)]
    -> (1,2)
[(0,0)], [(0,0)]
    -> (0,0)          # P and T are same point
[(0,0),(1,0)], [(0,0)]
    -> (1,0)          # P and T contain the same point
[(1,0),(0,1)], [(0,0)]
    -> (1,0) or (0,1) # multiple points are most isolated
[(123,456)], [(1,2),(3,4),(5,6)]
    -> (123,456)      # P only contains 1 point
[(6,0),(6,4),(5,-3),(4,1),(6,3)], [(3,3)]
    -> (5,-3)         # T only contains 1 point
[(1,1),(-1,-1)], [(2,2),(-2,-2)]
    -> (1,1) or (-1,-1) # multiple points do not maximize distance from all points

*/

#[derive(Debug, Copy, Clone, PartialEq)]
struct Point {
    x: f64,
    y: f64,
}

fn main() {
    assert_eq!(
        isolated(
            vec![
                Point { x: 1.0, y: 2.0 },
                Point { x: 3.0, y: 4.0 },
                Point { x: 5.0, y: 6.0 },
            ],
            vec![
                Point { x: 2.0, y: 6.0 },
                Point { x: 7.0, y: 1.0 },
                Point { x: 7.0, y: 5.0 },
            ],
        ),
        Point { x: 1.0, y: 2.0 },
    );

    assert_eq!(
        isolated(
            vec![Point { x: 0.0, y: 0.0 },],
            vec![Point { x: 0.0, y: 0.0 },],
        ),
        Point { x: 0.0, y: 0.0 },
    );

    assert_eq!(
        isolated(
            vec![Point { x: 0.0, y: 0.0 }, Point { x: 1.0, y: 0.0 }],
            vec![Point { x: 0.0, y: 0.0 },],
        ),
        Point { x: 1.0, y: 0.0 },
    );

    assert_eq!(
        isolated(
            vec![Point { x: 1.0, y: 0.0 }, Point { x: 0.0, y: 1.0 }],
            vec![Point { x: 0.0, y: 0.0 },],
        ),
        Point { x: 1.0, y: 0.0 },
    );

    assert_eq!(
        isolated(
            vec![Point { x: 123.0, y: 456.0 }],
            vec![
                Point { x: 1.0, y: 2.0 },
                Point { x: 3.0, y: 4.0 },
                Point { x: 5.0, y: 6.0 }
            ],
        ),
        Point { x: 123.0, y: 456.0 },
    );

    assert_eq!(
        isolated(
            vec![
                Point { x: 6.0, y: 0.0 },
                Point { x: 6.0, y: 4.0 },
                Point { x: 5.0, y: -3.0 },
                Point { x: 4.0, y: 1.0 },
                Point { x: 6.0, y: 3.0 },
                Point { x: 3.0, y: 3.0 }
            ],
            vec![Point { x: 3.0, y: 3.0 },],
        ),
        Point { x: 5.0, y: -3.0 },
    );

    assert_eq!(
        isolated(
            vec![Point { x: 1.0, y: 1.0 }, Point { x: -1.0, y: -1.0 }],
            vec![Point { x: 2.0, y: 2.0 }, Point { x: -2.0, y: -2.0 },],
        ),
        Point { x: 1.0, y: 1.0 },
    );
}

fn isolated(p: Vec<Point>, t: Vec<Point>) -> Point {
    let mut r = Point { x: 0.0, y: 0.0 };
    let mut m = 0.0;
    for p in &p {
        let mut d = 0.0;
        for t in &t {
            d += distance2(*p, *t);
        }
        if m < d {
            (m, r) = (d, *p);
        }
    }
    r
}

fn distance2(p: Point, q: Point) -> f64 {
    let dx = p.x - q.x;
    let dy = p.y - q.y;
    (dx * dx) + (dy * dy)
}

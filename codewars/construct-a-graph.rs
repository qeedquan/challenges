/*

Task
Given a list of points, construct a graph that includes all of those points and the position (0, 0).

Points will be objects like so: {x: 1, y: -1}.

A graph should be represented as a 2d array.

Example:

Input:
constructGraph([{x: 2, y: 2}, {x: -2, y: -2}])

Output:
[
  [' ', ' ', '|', ' ', '*'],
  [' ', ' ', '|', ' ', ' '],
  ['-', '-', '+', '-', '-'],
  [' ', ' ', '|', ' ', ' '],
  ['*', ' ', '|', ' ', ' '],
]

Points on the graph are represented as '*', and the position (0, 0) is represented by a '+'.

All positions along the x axis should be '-', and all postions along the y axis should be '|'. The rest of the positions should be spaces: ' '.

Also, if a point is on the x or y axis, the default char should be replaced with the point char: '*'.

Example:

Input:
constructGraph([{x: 0, y: 0}, {x: 1, y: 4}]);

Output:
[
  ['|', '*']
  ['|', ' '],
  ['|', ' '],
  ['|', ' '],
  ['*', '-']
]// ^
 //this is (0, 0)

Graphs should be as minimal as posible while still retaining a rectangular shape. They should be just large enough to include all the points and the position (0, 0).

If no points are given, the graph should just include the position (0, 0). Points might have the same value sometimes.

More Examples:

Input:
constructGraph([]);

Output:
[['+']]

Input:
constructGraph([{x: 1, y: 2}, {x: 1, y: 2}]);

Output:
[
  ['|', '*'],
  ['|', ' '],
  ['+', '-']
]

Input:
constructGraph([{x: 0, y: 3}]);

Output:
[
  ['*'],
  ['|'],
  ['|'],
  ['+']
]

Input:
constructGraph([{x: -2, y: -3}, {x: 1, y: -3}]);

Output:
[
  ['-', '-', '+', '-'],
  [' ', ' ', '|', ' '],
  [' ', ' ', '|', ' '],
  ['*', ' ', '|', '*']
]

*/

use std::cmp::*;

struct Point {
    x: isize,
    y: isize,
}

fn main() {
    draw(&construct(&[Point { x: 2, y: 2 }, Point { x: -2, y: -2 }]));
    draw(&construct(&[Point { x: 0, y: 0 }, Point { x: 1, y: 4 }]));
    draw(&construct(&[]));
    draw(&construct(&[Point { x: 1, y: 2 }, Point { x: 1, y: 2 }]));
    draw(&construct(&[Point { x: 0, y: 3 }]));
    draw(&construct(&[Point { x: -2, y: -3 }, Point { x: 1, y: -3 }]));
}

fn construct(p: &[Point]) -> Vec<Vec<char>> {
    let (mut x0, mut y0) = (0, 0);
    let (mut x1, mut y1) = (0, 0);
    for p in p {
        x0 = min(x0, p.x);
        y0 = min(y0, p.y);
        x1 = max(x1, p.x);
        y1 = max(y1, p.y);
    }

    let w = (x1 - x0 + 1) as usize;
    let h = (y1 - y0 + 1) as usize;
    let mut g = vec![vec![' '; w]; h];
    for y in y0..=y1 {
        for x in x0..=x1 {
            let xi = (x - x0) as usize;
            let yi = (y1 - y) as usize;
            match (x, y) {
                (0, 0) => g[yi][xi] = '+',
                (0, _) => g[yi][xi] = '|',
                (_, 0) => g[yi][xi] = '-',
                (_, _) => (),
            }
        }
    }

    for p in p {
        if p.x == 0 && p.y == 0 {
            continue;
        }
        let xi = (p.x - x0) as usize;
        let yi = (y1 - p.y) as usize;
        g[yi][xi] = '*';
    }

    g
}

fn draw(g: &Vec<Vec<char>>) {
    for y in g {
        println!("{:?}", y);
    }
    println!();
}

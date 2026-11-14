/*

You have to find maximum sum of numbers from top left corner of a matrix to bottom right corner.

You can only go down or right.

Input data
Matrix will be square M x M, 4 ≤ M ≤ 60
Matrix will have only positive integers N.
10 ≤ N ≤ 200
Example
matrix = [[20, 20, 10, 10],
          [10, 20, 10, 10],
          [10, 20, 20, 20],
          [10, 10, 10, 20]]
Solution
S: start
E: end
matrix = [[S, ↓, -, -],
          [-, ↓, -, -],
          [-, →, →, ↓],
          [-, -, -, E]] 
          
matrix = [[20, 20,   ,   ],
          [,   20,   ,   ],
          [,   20, 20, 20],
          [,     ,   , 20]]

Top Left Corner, Right, Down, Down, Right, Right, Bottom Right Corner 

20 + 20 + 20 + 20 + 20 + 20 + 20 = 140

*/

use std::cmp::max;

fn main() {
    assert_eq!(
        bigsum(&[
            &[20, 20, 10, 10],
            &[10, 20, 10, 10],
            &[10, 20, 20, 20],
            &[10, 10, 10, 20],
        ]),
        140
    );
}

fn bigsum(m: &[&[isize]]) -> isize {
    if m.len() == 0 || m[0].len() == 0 {
        return 0;
    }

    let w = m[0].len();
    let h = m.len();
    let mut p = vec![0; w];
    for y in 0..h {
        p[0] += m[y][0];
        for x in 1..w {
            p[x] = max(p[x], p[x - 1]) + m[y][x];
        }
    }
    return p[w - 1];
}

/*

For a cell with coordinates x,y in a table of size M×N, output the coordinates of its neighboring cells.
Neighboring cells are those that share a side with the specified cell.

Input
Natural numbers M,N,x,y are given, where 1≤x≤M≤10^9, 1≤y≤N≤10^9.

Output
Print the coordinate pairs of the neighboring cells of the specified cell in any order.

Examples
Input #1
3 3
2 2

Answer #1
2 1
1 2
2 3
3 2

*/

fn main() {
    solve(3, 3, 2, 2);
}

fn solve(w: isize, h: isize, x: isize, y: isize) {
    if x - 1 > 0 {
        println!("{} {}", x - 1, y);
    }
    if x + 1 <= w {
        println!("{} {}", x + 1, y);
    }
    if y - 1 > 0 {
        println!("{} {}", x, y - 1);
    }
    if y + 1 <= h {
        println!("{} {}", x, y + 1);
    }
}

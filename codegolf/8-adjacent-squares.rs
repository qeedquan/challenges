/*

List the coordinates of 8 squares adjacent to (0, 0) in a 2d grid. Namely,

[(1,-1),(1,0),(1,1),(0,1),(-1,1),(-1,0),(-1,-1),(0,-1)]

Order does not matter. The goal is to store the points into a list. Shortest answer wins.

*/

fn main() {
    output();
}

fn output() {
    let mut p = vec![];
    for x in -1..2 {
        for y in -1..2 {
            if x != 0 || y != 0 {
                p.push((x, y));
            }
        }
    }
    println!("{:?}", p);
}

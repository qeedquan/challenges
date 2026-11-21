/*

Question: Print out all the coordinates of a NxN grid. Preferably in C, however other languages also accepted

Input: N (integer)

Output: for N=3, a 3x3 grid:

0,0
1,0
2,0
0,1
1,1
2,1
0,2
1,2
2,2

*/

fn main() {
    coordinates(3);
}

fn coordinates(n: isize) {
    for y in 0..n {
        for x in 0..n {
            println!("{},{}", x, y);
        }
    }
}

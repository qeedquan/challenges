/*

For the given positive integer n print the square frame of size n×n from stars, filled with spaces as shown in the sample.

Input
One positive integer n (n≤100).

Output
Print the square frame of size n×n.

Examples
Input #1
5

Answer #1
*****
*   *
*   *
*   *
*****

*/

fn main() {
    solve(5);
}

fn solve(n: usize) {
    for y in 0..n {
        for x in 0..n {
            print!("{}", at(x, y, n, n));
        }
        println!();
    }
}

fn at(x: usize, y: usize, w: usize, h: usize) -> char {
    if x == 0 || x == w - 1 || y == 0 || y == h - 1 {
        return '*';
    }
    return ' ';
}

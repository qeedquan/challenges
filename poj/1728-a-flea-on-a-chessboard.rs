/*

Description

An infinite chessboard is obtained by extending a finite chessboard to the right and up infinitely. Each square of the chessboard is either black or white with the side of S milimiters, 0 < S <= 1000. The leftmost bottom square of the chessboard is black. A flea is positioned on the chessboard at the point (x, y) (given in milimeters) and makes jumps by jumping dx milimeters to the right and dy milimiters up, 0 < dx, dy, that is, a flea at position (x, y) after one jump lands at position (x+dx, y+dy).
Given the starting position of the flea on the board your task is to find out after how many jumps the flea will reach a white square. If the flea lands on a boundary between two squares then it does not count as landing on the white square. Note that it is possible that the flea never reaches a white square.

http://poj.org/images/1728_1.jpg

Input

Each test case consists of one line of input containing five non-negative numbers separated by white space and giving integers S, x, y, dx, and dy. An input line containing five zeroes follows the last test case.

Output

For test case print one line of output in the format shown in the sample.
Sample Input

10 2 3 3 2
100 49 73 214 38
25 0 0 5 25
407 1270 1323 1 1
18 72 6 18 6
407 1270 1170 100 114
0 0 0 0 0

Sample Output

After 3 jumps the flea lands at (11, 9).
After 1 jumps the flea lands at (263, 111).
The flea cannot escape from black squares.
After 306 jumps the flea lands at (1576, 1629).
The flea cannot escape from black squares.
After 0 jumps the flea lands at (1270, 1170).
Source

Waterloo local 2004.01.31

*/

fn main() {
    assert_eq!(passage(10, 2, 3, 3, 2), (3, 11, 9));
    assert_eq!(passage(100, 49, 73, 214, 38), (1, 263, 111));
    assert_eq!(passage(25, 0, 0, 5, 25), (-1, 0, 0));
    assert_eq!(passage(407, 1270, 1323, 1, 1), (306, 1576, 1629));
    assert_eq!(passage(18, 72, 6, 18, 6), (-1, 0, 0));
    assert_eq!(passage(407, 1270, 1170, 100, 114), (0, 1270, 1170));
}

fn passage(s: isize, mut x: isize, mut y: isize, dx: isize, dy: isize) -> (isize, isize, isize) {
    if s < 1 || dx < 1 || dy < 1 {
        return (-1, -1, -1);
    }

    let mut c = 0;
    loop {
        if c > 2 * s {
            return (-1, 0, 0);
        }

        let cx = x / s;
        let cy = y / s;
        let rx = x % s;
        let ry = y % s;
        if (cx + cy) % 2 == 1 && rx != 0 && ry != 0 {
            return (c, x, y);
        }

        x += dx;
        y += dy;
        c += 1;
    }
}

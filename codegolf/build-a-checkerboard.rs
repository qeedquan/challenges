/*

For this challenge you will print the coordinates and color of each piece at the start of a game of checkers.

Enter the x and y (comma seperated) for every square (indexed 0-7) on a checkerboard, followed by a "r" or "b" (for red or black) where the top of the board (closer to y=0) is red and the bottom is black.
newlines between pieces are required and no spaces are necessary.

This is code-golf so answers are scored in bytes with fewer bytes being better.

Trailing newlines are allowed but not necessary and the order must be exactly of that below.

Desired output:

0,0r
0,2r
0,4r
0,6r
1,1r
1,3r
1,5r
1,7r
2,0r
2,2r
2,4r
2,6r
5,1b
5,3b
5,5b
5,7b
6,0b
6,2b
6,4b
6,6b
7,1b
7,3b
7,5b
7,7b

*/

fn main() {
    checkerboard();
}

fn checkerboard() {
    let mut bo = 0;
    for i in 0..24 {
        let mut a = i / 4;
        if a > 2 {
            a += 2;
        }

        let b = (2 * (i & 3)) + bo;
        if (i & 3) == 3 {
            bo = 1 - bo;
        }

        let mut c = 'r';
        if (i / 12) > 0 {
            c = 'b';
        }

        println!("{},{}{}", a, b, c);
    }
}

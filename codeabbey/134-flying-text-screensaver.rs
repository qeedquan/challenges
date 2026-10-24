/*

This useless program is sometimes proposed by school teachers: using extended console functions for positioning cursor and printing text in any possible position on the screen, pupils are to create effect of the flying text with the given string.

Text should move diagonally with the constant speed (for example, 3 cells per second) and bounce from the borders. Bouncing means that when the string reaches last or first line, it changes the vertical direction - and when its end or start touches last or first column respectively - it changes the horizontal direction.

Play with the demo above to get better idea of how it works. Or, perhaps, write such program using what means your programming language offer - and see it in action.

Your task now is to track the path of the flying text.

Input data will contain Width and Height of the imaginary screen and the Length of text string.
Answer should dump pairs of coordinates X and Y of the beginning of the text for first 100 steps (spaces should be used to separate values in the pair and pairs themselves) - i.e. 202 integers in total (including coordinates of the starting position).

Coordinate system of the screen usually has the (0, 0) in the left top corner.

Example:

input data:
9 3 4

answer:
0 0 1 1 2 2 3 1 4 0 5 1 4 2 3 1 2 0 ... 4 0 3 1 2 2 1 1 0 0

*/

fn main() {
    solve(9, 3, 4);
}

fn solve(w: isize, h: isize, l: isize) {
    let (mut x, mut y) = (0, 0);
    let (mut px, mut py) = (0, 0);
    let (mut dx, mut dy) = (1, 1);
    for _ in 0..=100 {
        println!("{x} {y}");
        x += dx;
        y += dy;
        if x < 0 || x + l > w {
            dx = -dx;
            x = px + dx;
        }
        if y < 0 || y >= h {
            dy = -dy;
            y = py + dy;
        }
        px = x;
        py = y;
    }
}

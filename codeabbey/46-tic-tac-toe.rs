/*

         |         |
         |         |
    1    |    2    |    3
         |         |
         |         |
---------+---------+---------
         |         |
         |         |
    4    |    5    |    6
         |         |
         |         |
---------+---------+---------
         |         |
         |         |
    7    |    8    |    9
         |         |
         |         |

Select the cell to put "X" [1..9]:

At this time we are not programming computer opponent for the game of Crosses and Noughts, but an important part for such an algorith - the checking function, which can tell whether the game is ended and won by one or another side.

The game is played on the square field 3 x 3. Let us suppose that the cells are numerated in the following way:

 1 | 2 | 3
---+---+---
 4 | 5 | 6
---+---+---
 7 | 8 | 9
Two players put their marks (X for first and O for second) in turns into any of free cells remaining. One who completes the straight line of three marks (three X-s or three O-s) immediately wins. Lines could be filled either in rows or columns or one of two diagonals (8 lines possible in total). For example suppose the following moves were performed:

 X   O
-------
 7
     5
 4
     1
 9
     2
 8
Which leads to the following position:

 O | O |
---+---+---
 X | O |
---+---+---
 X | X | X
with first player (Crosses) winning by completing the third row.

Problem statement
You will be given the sequence of moves (supposing the first move is always done by X) - by the numbers of cells where marks are placed - and your task is to determine, at which step the first line was completed (by any side).

Input data contain the number of test-cases in the first line.
Next lines have one test-case each - exactly 9 numbers, describing cells to which moves are performed in order.
Answer should contain the number of the move at which game is won by one of players (starting from 1) or 0 if the game is drawn (no winner) after the last move.

Example:

input data:
3
7 5 4 1 9 2 8 3 6
5 1 3 7 6 4 2 9 8
5 1 2 8 6 4 7 3 9

answer:
7 6 0

*/

use std::cmp::PartialEq;

fn main() {
    assert_eq!(solve(&[7, 5, 4, 1, 9, 2, 8, 3, 6]), 7);
    assert_eq!(solve(&[5, 1, 3, 7, 6, 4, 2, 9, 8]), 6);
    assert_eq!(solve(&[5, 1, 2, 8, 6, 4, 7, 3, 9]), 0);
}

fn solve(moves: &[usize]) -> usize {
    let mut board = [[0; 3]; 3];
    let mut player = 2;
    for index in 0..moves.len() {
        let position = moves[index] - 1;
        board[position / 3][position % 3] = player;
        if check(&board) {
            return index + 1;
        }
        player ^= 1;
    }
    return 0;
}

fn check(board: &[[usize; 3]; 3]) -> bool {
    for i in 0..3 {
        if equals3(board[i][0], board[i][1], board[i][2]) {
            return true;
        }
        if equals3(board[0][i], board[1][i], board[2][i]) {
            return true;
        }
    }

    if equals3(board[0][0], board[1][1], board[2][2]) {
        return true;
    }
    if equals3(board[2][0], board[1][1], board[0][2]) {
        return true;
    }

    return false;
}

fn equals3<T: Default + PartialEq>(a: T, b: T, c: T) -> bool {
    return a == b && b == c && a != T::default();
}

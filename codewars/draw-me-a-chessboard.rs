/*

A grid is a perfect starting point for many games (Chess, battleships, Candy Crush!).

Making a digital chessboard I think is an interesting way of visualising how loops can work together.

Your task is to write a function that takes two integers rows and columns and returns a chessboard pattern as a two dimensional array.

So chessBoard(6,4) should return an array like this:

[
    ["O","X","O","X"],
    ["X","O","X","O"],
    ["O","X","O","X"],
    ["X","O","X","O"],
    ["O","X","O","X"],
    ["X","O","X","O"]
]

And chessBoard(3,7) should return this:

[
    ["O","X","O","X","O","X","O"],
    ["X","O","X","O","X","O","X"],
    ["O","X","O","X","O","X","O"]
]

The white spaces should be represented by an: 'O'

and the black an: 'X'

The first row should always start with a white space 'O'

*/

fn main() {
    draw(chessboard(6, 4));
    draw(chessboard(3, 7));
}

fn draw(board: Vec<Vec<char>>) {
    for array in board {
        println!("{:?}", array);
    }
    println!();
}

fn chessboard(rows: usize, cols: usize) -> Vec<Vec<char>> {
    let mut board = vec![];
    for row in 0..rows {
        let mut array = vec![];
        for col in 0..cols {
            if row % 2 == col % 2 {
                array.push('O');
            } else {
                array.push('X');
            }
        }
        board.push(array);
    }
    board
}

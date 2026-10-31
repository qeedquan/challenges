/*

A latin square is an n × n array filled with the integers 1 to n, each occurring once in each row and column.

Here are examples of latin squares of size 4 and 7:

[[1, 4, 3, 2],      [[2, 3, 1, 7, 4, 6, 5], 
 [4, 3, 2, 1],       [7, 1, 6, 5, 2, 4, 3], 
 [3, 2, 1, 4],       [6, 7, 5, 4, 1, 3, 2], 
 [2, 1, 4, 3]]       [4, 5, 3, 2, 6, 1, 7], 
                     [5, 6, 4, 3, 7, 2, 1], 
                     [1, 2, 7, 6, 3, 5, 4], 
                     [3, 4, 2, 1, 5, 7, 6]]
                     
Latin squares have many practical uses, for example in error-correcting-codes and the design of agricultural experiments. See https://en.wikipedia.org/wiki/Latin_square for more details. Sudoku is a special type of 9 x 9 latin square, with additional conditions.

Task: Write a function that returns a latin square for any positive integer n.

You might also enjoy Latin Square Validator ( https://www.codewars.com/kata/646254375cee7a000ffaa404 ) and Euler Squares ( https://www.codewars.com/kata/6470e15f4f0b26052c6151cd ).

*/

fn main() {
    println!("{:?}", latinsquare(4));
    println!("{:?}", latinsquare(7));
}

fn latinsquare(size: usize) -> Vec<Vec<usize>> {
    let mut squares = vec![];
    for i in 0..size {
        let mut line = vec![];
        for j in 1..=size {
            let mut value = (i + j) % size;
            if value == 0 {
                value = size;
            }
            line.push(value);
        }
        squares.push(line);
    }
    squares
}

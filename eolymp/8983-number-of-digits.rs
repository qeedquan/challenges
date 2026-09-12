/*

Given a string that contains an expression of numbers, signs of arithmetic operations and brackets. Find the number of digits used in the expression.

Input
Arithmetic expression containing numbers, brackets, and arithmetic characters.

Output
Print the number of digits in the expression.

Examples
Input #1
9*8+76-54/3+2**10

Answer #1
10

*/

fn main() {
    assert_eq!(solve("9*8+76-54/3+2**10"), 10);
}

fn solve(expression: &'static str) -> usize {
    let mut digits = 0;
    for symbol in expression.chars() {
        match symbol {
            '0'..='9' => digits += 1,
            _ => (),
        }
    }
    digits
}

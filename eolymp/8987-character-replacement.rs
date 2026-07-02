/*

Replace all occurrences of the letter 'a' with 'b' and vice versa in the given string.

Input
One string with a length of no more than 200 characters, containing only Latin letters and spaces.

Output
Print the string with the replacements made.

Examples
Input #1
abrakadabra

Answer #1
barbkbdbarb

*/

fn main() {
    assert_eq!(solve("abrakadabra"), "barbkbdbarb");
}

fn solve(input: &'static str) -> String {
    let mut output = String::new();
    for symbol in input.chars() {
        if symbol == 'a' {
            output.push('b');
        } else if symbol == 'b' {
            output.push('a');
        } else {
            output.push(symbol);
        }
    }
    output
}

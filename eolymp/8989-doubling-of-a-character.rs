/*

Given a string composed of English letters and spaces, your task is to double every occurrence of the letter a within it.

Input
A single string made up of English letters and spaces.

Output
Answer to the problem.

Examples

Input #1
abrakadabra

Answer #1
aabraakaadaabraa

*/

fn main() {
    assert_eq!(solve("abrakadabra"), "aabraakaadaabraa");
}

fn solve(input: &'static str) -> String {
    let mut output = String::new();
    for symbol in input.chars() {
        output.push(symbol);
        if symbol == 'a' {
            output.push(symbol);
        }
    }
    output
}

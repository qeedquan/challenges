/*

When provided with a String, capitalize all vowels

For example:

Input : "Hello World!"

Output : "HEllO WOrld!"

Note: Y is not a vowel in this kata.

*/

fn main() {
    assert_eq!(swap("Hello World!"), "HEllO WOrld!");
}

fn swap(input: &'static str) -> String {
    let mut output = String::new();
    for symbol in input.chars() {
        let symbol = match symbol {
            'a' | 'e' | 'i' | 'o' | 'u' => symbol.to_ascii_uppercase(),
            _ => symbol,
        };
        output.push(symbol);
    }
    output
}

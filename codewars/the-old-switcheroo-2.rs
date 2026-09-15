/*

This is a follow up from my kata The old switcheroo

Write the function :

function encode(str)
that takes in a string str and replaces all the letters with their respective positions in the English alphabet.

encode('abc') == '123'   // a is 1st in English alpabet, b is 2nd and c is 3rd
encode('codewars') == '315452311819'
encode('abc-#@5') == '123-#@5'
String are case sensitive.

// Bonus point if you don't use toLowerCase()

*/

fn main() {
    assert_eq!(encode("abc"), "123");
    assert_eq!(encode("codewars"), "315452311819");
    assert_eq!(encode("abc-#@5"), "123-#@5");
}

fn encode(input: &'static str) -> String {
    let mut output = String::new();
    for symbol in input.chars() {
        match symbol {
            'a'..='z' | 'A'..='Z' => output.push_str(&remap(symbol)),
            _ => output.push(symbol),
        }
    }
    output
}

fn remap(symbol: char) -> String {
    let symbol = symbol.to_ascii_lowercase();
    let value = (symbol as u32) - 96;
    format!("{value}")
}

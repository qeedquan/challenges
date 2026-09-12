/*

Write a function that accepts a string, and returns the same string with all even indexed characters in each word upper cased, and all odd indexed characters in each word lower cased. The indexing just explained is zero based, so the zero-ith index is even, therefore that character should be upper cased and you need to start over for each word.

The passed in string will only consist of alphabetical characters and spaces(' '). Spaces will only be present if there are multiple words. Words will be separated by a single space(' ').

Examples:
"String" => "StRiNg"
"Weird string case" => "WeIrD StRiNg CaSe"

*/

fn main() {
    assert_eq!(weirdcase("String"), "StRiNg");
    assert_eq!(weirdcase("Weird string case"), "WeIrD StRiNg CaSe");
    assert_eq!(weirdcase("This is a test"), "ThIs Is A TeSt");
    assert_eq!(weirdcase(""), "");
    assert_eq!(weirdcase("unique"), "UnIqUe");
    assert_eq!(weirdcase("UPPER CASE"), "UpPeR CaSe");
    assert_eq!(weirdcase("lower case"), "LoWeR CaSe");
}

fn weirdcase(string: &'static str) -> String {
    let mut output = String::new();
    let mut index = 0;
    for symbol in string.chars() {
        if index & 1 == 0 {
            output.push(symbol.to_ascii_uppercase());
        } else {
            output.push(symbol.to_ascii_lowercase());
        }

        if symbol.is_whitespace() {
            index = 0;
        } else {
            index ^= 1;
        }
    }
    output
}

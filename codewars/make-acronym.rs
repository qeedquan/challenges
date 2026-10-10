/*

Write function which takes a string and make an acronym of it.

Rule of making acronym in this kata:

split string to words by space char
take every first letter from word in given string
uppercase it
join them toghether
Eg:

Code wars -> C, w -> C W -> CW

Note: There will be at least two words in the given string!

*/

fn main() {
    assert_eq!(acronym("Code wars"), "CW");
    assert_eq!(acronym("Water Closet"), "WC");
    assert_eq!(acronym("Portable Network Graphics"), "PNG");
}

fn acronym(input: &'static str) -> String {
    let mut result = format!("");
    for word in input.split(" ") {
        if let Some(ch) = word.chars().nth(0) {
            result = format!("{result}{}", ch.to_ascii_uppercase());
        }
    }
    result
}

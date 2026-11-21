/*

Take a string and return a hash with all the ascii values of the characters in the string. Returns nil if the string is empty. The key is the character, and the value is the ascii value of the character. Repeated characters are to be ignored and non-alphebetic characters as well.

*/

use std::collections::HashMap;

fn main() {
    println!("{:?}", char2ascii("aaa"));
    println!("{:?}", char2ascii("hello, world!"));
    println!("{:?}", char2ascii("ABaa ^"));
}

fn char2ascii(string: &'static str) -> HashMap<char, u32> {
    let mut map = HashMap::new();
    for character in string.chars() {
        if character.is_alphabetic() {
            map.insert(character, character as u32);
        }
    }
    map
}

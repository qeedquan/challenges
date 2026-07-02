/*

Given a string as input, move all of its vowels to the end of the string, in the same order as they were before.

Vowels are (in this kata): a, e, i, o, u

Note: all provided input strings are lowercase.

Examples
"day"    ==>  "dya"
"apple"  ==>  "pplae"

*/

fn main() {
    assert_eq!(move_vowel("day"), "dya");
    assert_eq!(move_vowel("apple"), "pplae");
}

fn move_vowel(s: &'static str) -> String {
    let mut s0 = String::new();
    let mut s1 = String::new();
    for c in s.chars() {
        if !isvowel(c) {
            s0.push(c);
        } else {
            s1.push(c);
        }
    }
    format!("{s0}{s1}")
}

fn isvowel(c: char) -> bool {
    match c {
        'A' | 'E' | 'I' | 'O' | 'U' | 'a' | 'e' | 'i' | 'o' | 'u' => true,
        _ => false,
    }
}

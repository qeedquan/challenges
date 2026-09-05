/*

Assume "#" is like a backspace in string. This means that string "a#bc#d" actually is "bd"

Your task is to process a string with "#" symbols.

Examples
"abc#d##c"      ==>  "ac"
"abc##d######"  ==>  ""
"#######"       ==>  ""
""              ==>  ""

*/

fn main() {
    assert_eq!(backspace("abc#d##c"), "ac");
    assert_eq!(backspace("abc##d######"), "");
    assert_eq!(backspace("#######"), "");
    assert_eq!(backspace(""), "");
}

fn backspace(sentence: &'static str) -> String {
    let mut result = String::new();
    for ch in sentence.chars() {
        if ch == '#' {
            result.pop();
        } else {
            result.push(ch);
        }
    }
    result
}

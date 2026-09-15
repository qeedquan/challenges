/*

Create a function to validate if a string is a valid hexadecimal.

Two patterns is valid

6 chars (ff00ff)
3 chars (f0f).

*/

fn main() {
    assert_eq!(ishex("ff00ff"), true);
    assert_eq!(ishex("f0f"), true);
    assert_eq!(ishex("f0f000000"), false);
    assert_eq!(ishex("xyz"), false);
}

fn ishex(string: &'static str) -> bool {
    for character in string.chars() {
        match character {
            '0'..='9' | 'a'..='f' | 'A'..='F' => (),
            _ => return false,
        };
    }

    match string.len() {
        3 | 6 => true,
        _ => false,
    }
}

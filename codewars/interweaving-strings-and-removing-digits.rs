/*

Your friend Rick is trying to send you a message, but he is concerned that it would get intercepted by his partner. He came up with a solution:

Add digits in random places within the message.

Split the resulting message in two. He wrote down every second character on one page, and the remaining ones on another. He then dispatched the two messages separately.

Write a function interweave(s1, s2) that reverses this operation to decode his message!

Example 1: interweave("hlo", "el") -> "hello" Example 2: interweave("h3lo", "el4") -> "hello"

Rick's a bit peculiar about his formats. He would feel ashamed if he found out his message led to extra white spaces hanging around the edges of his message...

*/

use std::str::Chars;

fn main() {
    assert_eq!(interweave("", ""), "");
    assert_eq!(interweave("hlo", "el"), "hello");
    assert_eq!(interweave("h3lo", "el4"), "hello");
}

fn interweave(string0: &'static str, string1: &'static str) -> String {
    let mut result = String::new();
    let mut chars0 = string0.chars();
    let mut chars1 = string1.chars();
    loop {
        if !getchar(&mut result, &mut chars0) {
            break;
        }
        if !getchar(&mut result, &mut chars1) {
            break;
        }
    }
    while getchar(&mut result, &mut chars0) {}
    while getchar(&mut result, &mut chars1) {}
    result
}

fn getchar(result: &mut String, chars: &mut Chars<'_>) -> bool {
    loop {
        let ch = chars.next();
        if ch == None {
            break;
        }

        let ch = ch.unwrap();
        if !ch.is_ascii_digit() {
            result.push(ch);
            return true;
        }
    }
    return false;
}

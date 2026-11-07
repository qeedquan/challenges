/*

Given a string containing only printable ASCII (codepoints 0x20 to 0x7E), write the shortest program or function that swaps the cases of A-Z and a-z.

If a character is in [A-Z], convert it to its lowercase version.
If a character is in [a-z], convert it to its uppercase version.
Otherwise, leave the character alone.

Test Cases
input -> output
abc -> ABC
ABC -> abc
Mixed Case -> mIXED cASE
1234 -> 1234
123#$%hIjK456 -> 123#$%HiJk456

*/

fn main() {
    assert_eq!(swap_letter_case("abc"), "ABC");
    assert_eq!(swap_letter_case("ABC"), "abc");
    assert_eq!(swap_letter_case("Mixed Case"), "mIXED cASE");
    assert_eq!(swap_letter_case("1234"), "1234");
    assert_eq!(swap_letter_case("123#$%hIjK456"), "123#$%HiJk456");
}

fn swap_letter_case(s: &'static str) -> String {
    let mut r = String::new();
    for c in s.chars() {
        if !c.is_ascii() {
            r.push(c);
        } else if c.is_uppercase() {
            r.push(c.to_ascii_lowercase());
        } else {
            r.push(c.to_ascii_uppercase());
        }
    }
    r
}

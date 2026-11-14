/*

## Task

Create a method to see whether the string is ALL CAPS.

### Examples (input -> output)


"c" -> False
"C" -> True
"hello I AM DONALD" -> False
"HELLO I AM DONALD" -> True
"ACSKLDFJSgSKLDFJSKLDFJ" -> False
"ACSKLDFJSGSKLDFJSKLDFJ" -> True

In this Kata, a string is said to be in ALL CAPS whenever it does not contain any lowercase letter so any string containing no letters at
all is trivially considered to be in ALL CAPS.

*/

fn main() {
    assert_eq!(allcaps("c"), false);
    assert_eq!(allcaps("C"), true);
    assert_eq!(allcaps("hello I AM DONALD"), false);
    assert_eq!(allcaps("HELLO I AM DONALD"), true);
    assert_eq!(allcaps("ACSKLDFJSgSKLDFJSKLDFJ"), false);
    assert_eq!(allcaps("ACSKLDFJSGSKLDFJSKLDFJ"), true);
}

fn allcaps(string: &'static str) -> bool {
    for character in string.chars() {
        if !character.is_uppercase() && character.is_lowercase() {
            return false;
        }
    }
    return true;
}

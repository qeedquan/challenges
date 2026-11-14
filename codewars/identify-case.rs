/*

We’ve all seen katas that ask for conversion from snake-case to camel-case, from camel-case to snake-case, or from camel-case to kebab-case — the possibilities are endless.

But if we don’t know the case our inputs are in, these are not very helpful.

Task:
So the task here is to implement a function (called id in Ruby/Crystal/JavaScript/CoffeeScript and case_id in Python/C) that takes a string, c_str, and returns a string with the case the input is in. The possible case types are “kebab”, “camel”, and ”snake”. If none of the cases match with the input, or if there are no 'spaces' in the input (for example in snake case, spaces would be '_'s), return “none”. Inputs will only have letters (no numbers or special characters).

Some definitions
Kebab case: lowercase-words-separated-by-hyphens

Camel case: lowercaseFirstWordFollowedByCapitalizedWords

Snake case: lowercase_words_separated_by_underscores

Examples:
id(“hello-world”) #=> “kebab”
id(“hello-to-the-world”) #=> “kebab”
id(“helloWorld”) #=> “camel”
id(“helloToTheWorld”) #=> “camel”
id(“hello_world”) #=> “snake”
id(“hello_to_the_world”) #=> “snake”
id(“hello__world”) #=> “none”
id(“hello_World”) #=> “none”
id(“helloworld”) #=> “none”
id(“hello-World”) #=> “none”

*/

fn main() {
    assert_eq!(id("hello-world"), "kebab");
    assert_eq!(id("hello-to-the-world"), "kebab");
    assert_eq!(id("helloWorld"), "camel");
    assert_eq!(id("helloToTheWorld"), "camel");
    assert_eq!(id("hello_world"), "snake");
    assert_eq!(id("hello_to_the_world"), "snake");
    assert_eq!(id("hello__world"), "none");
    assert_eq!(id("hello_World"), "none");
    assert_eq!(id("helloworld"), "none");
    assert_eq!(id("hello-World"), "none");
}

fn id(string: &'static str) -> &'static str {
    let (mut kind, mut prev) = (0x0, ' ');
    for code in string.chars() {
        match code {
            'a'..'z' => {
                prev = code;
                continue;
            }
            'A'..'Z' => kind |= 0x1,
            '-' => kind |= 0x2,
            '_' => kind |= 0x4,
            _ => return "none",
        }
        if code == prev || (code.is_uppercase() && prev.is_uppercase()) {
            return "none";
        }
        prev = code;
    }

    match kind {
        0x1 => "camel",
        0x2 => "kebab",
        0x4 => "snake",
        _ => "none",
    }
}

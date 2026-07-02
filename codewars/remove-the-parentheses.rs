/*

Remove the parentheses
In this kata you are given a string for example:

"example(unwanted thing)example"
Your task is to remove everything inside the parentheses as well as the parentheses themselves.

The example above would return:

"exampleexample"
Notes
Other than parentheses only letters and spaces can occur in the string. Don't worry about other brackets like "[]" and "{}" as these will never appear.
There can be multiple parentheses.
The parentheses can be nested.

*/

fn main() {
    assert_eq!(rmp("a(b(c))"), "a");
    assert_eq!(rmp("a (bc d)e"), "a e");
    assert_eq!(rmp("(first group) (second group) (third group)"), "  ");
    assert_eq!(rmp("example(unwanted thing)example"), "exampleexample");
    assert_eq!(rmp("example (unwanted thing) example"), "example  example");
    assert_eq!(
        rmp("hello example (words(more words) here) something"),
        "hello example  something"
    );
}

fn rmp(s: &'static str) -> String {
    let mut r = String::new();
    let mut p = 0;
    for c in s.chars() {
        if c == '(' {
            p += 1;
        } else if c == ')' {
            p -= 1;
        } else if p == 0 {
            r.push(c);
        }
    }
    r
}

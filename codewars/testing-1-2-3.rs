/*

Your team is writing a fancy new text editor and you've been tasked with implementing the line numbering.

Write a function which takes a list of strings and returns each line prepended by the correct number.

The numbering starts at 1. The format is n: string. Notice the colon and space in between.

Examples:

number([]) // => []
number(["a", "b", "c"]) // => ["1: a", "2: b", "3: c"]

*/

fn main() {
    let empty: Vec<String> = vec![];
    assert_eq!(number(vec![]), empty);
    assert_eq!(number(vec!["a", "b", "c"]), vec!["1: a", "2: b", "3: c"]);
}

fn number(lines: Vec<&'static str>) -> Vec<String> {
    let mut result = vec![];
    let mut lineno = 1;
    for line in lines {
        result.push(format!("{}: {}", lineno, line));
        lineno += 1;
    }
    result
}
